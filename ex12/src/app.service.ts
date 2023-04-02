/* eslint-disable prettier/prettier */
import { MailerService } from '@nestjs-modules/mailer';
import { ConflictException, HttpException, Injectable } from '@nestjs/common';

@Injectable()
export class MailService {
  constructor(private readonly mailerService: MailerService) {}

  async sendHello(): Promise<string> {
    await this.mailerService
      .sendMail({
        to: 'codeyoma@gmail.com',
        from: 'wonderful.samcheok@gmail.com',
        subject: 'Hello',
        text: 'Hello World',
        html: '<b>Hello World</b>',
        template: './confirmation',
      })
      .then((result) => {
        console.log(result);
      })
      .catch((error) => {
        throw new HttpException(error, 500, {
          cause: new Error(error.message),
        });
      });
   return "Success send email.";
  }

  async sendHelloFile(file : string): Promise<string> {
    const send_file = (file || "42.png");
    await this.mailerService
      .sendMail({
        to: 'codeyoma@gmail.com',
        from: 'wonderful.samcheok@gmail.com',
        subject: 'Hello',
        text: 'Hello World',
        html: '<b>Hello World</b>',
        template: './confirmation',
        attachments:[{
          path: __dirname + '/../file/' + send_file,
          filename: send_file,
          contentDisposition: "attachment",
        }]
      })
      .then((result) => {
        console.log(result);
      })
      .catch((error) => {
        throw new HttpException(error, 500, {
          cause: new Error(error.message),
        });
      });
    return "Success send email with attachment.";
  }

  sayHello(): string {
    return 'Hello World!';
  }

}

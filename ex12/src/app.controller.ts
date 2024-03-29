import { Controller, Get, Param } from '@nestjs/common';
import { MailService } from './app.service';

@Controller()
export class AppController {
  constructor(private readonly mailService: MailService) {}

  @Get()
  sayHello(): string {
    return 'Hello World!';
  }

  @Get('/smtp')
  sendHello(): Promise<string> {
    return this.mailService.sendHello();
  }

  @Get('/smtp_file/:file')
  sendHelloFile(@Param('file') file: string): Promise<string> {
    return this.mailService.sendHelloFile(file);
  }

}

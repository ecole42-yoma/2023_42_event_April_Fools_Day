import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { MailService } from './app.service';
import { MailerModule } from '@nestjs-modules/mailer';
import { HandlebarsAdapter } from '@nestjs-modules/mailer/dist/adapters/handlebars.adapter';

@Module({
  imports: [
    MailerModule.forRoot({
      transport: {
        host: 'smtp.gmail.com',
        port: 587,
        auth: {
          user: process.env.MAIL_USER || "wonderful.samcheok@gmail.com",
          pass: process.env.MAIL_PASS || "ppiietpmglnzknmz",
        },
      },
      template: {
        dir: __dirname + '/templates',
        adapter: new HandlebarsAdapter(),
        options: {
          strict: true,
        },
      },
    }),
  ],
  controllers: [AppController],
  providers: [MailService],
})
export class AppModule {}

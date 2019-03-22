#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<termios.h>
#include<stdlib.h>
#include<ncurses.h>
#include<locale.h>
#include <unistd.h>
#include <termios.h>
#include <assert.h>
char name[80],pas[80],tmp[80];
#define     SIZE    200
//定义按键们的宏
#define  UP   "\033[A"
#define  DOWN   "\033[B"
#define BACKSPACE 127
void login();
void passwd1();
int getch1(void);
int getch2(void);
int s=0;
int getch1()
{
    int c = 0;
    int res =  1;
    struct termios org_opts, new_opts;

    res = tcgetattr(STDIN_FILENO, &org_opts);
    assert(res == 0);
    memcpy(&new_opts, &org_opts, sizeof(org_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);

    c = getchar();

    res = tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    assert(res == 0);
    return c;
}
int getch2(void)
{
        struct termios tm, tm_old;
        int fd = STDIN_FILENO, c;
        if(tcgetattr(fd, &tm) < 0)
                return -1;
        tm_old = tm;
        cfmakeraw(&tm);
        if(tcsetattr(fd, TCSANOW, &tm) < 0)
                return -1;
        c = fgetc(stdin);
        if(tcsetattr(fd, TCSANOW, &tm_old) < 0)
                return -1;
        return c;
}

void regist()
{
    system("gzexe  -d user.txt");
     system("rm  -rf user.txt~");   
  system("clear");
    int i=0;
    int j=0;
    int flag=1;
    char ch;
    char text[80];
    FILE *fp;
  printf("            注册界面\n");
  printf("------------------------------------------------\n");
      printf("请输入账号(不能含有空格,下划线,不得少于八位)\n");
   scanf("%s",name);
   j=strlen(name);
          while(j<8)
       {
         printf("请重新输入账号(不得少于八位)！\n");
          memset(name,0,sizeof(name));
          scanf("%s",name);                                                  
          j=strlen(name);
       }
    if(NULL!=(fp=fopen("user.txt","r")))//以读写形式打开文件，如果存在则创立
    {   
     while(!feof(fp)&&flag==1)
    {
        memset(text, 0, sizeof(text));
         setbuf(stdin, NULL);
       fgets(text,j+1,fp);
        if(strcmp(name,text)==0)
        {//判断字符是否相等
            printf("请重新输入账号（不少于八位）\n");
            memset(name,0,sizeof(name));
            scanf("%s",name);
        }
        j=strlen(name);
    }
    }
     fclose(fp);
//  struct termios old;
 // struct termios news;
      //old保存当前的终端参数，new用来保存修改后的终>
//     tcgetattr(0,&old);//将tcgetattr()获取到的stdin参数存到old中
//     news=old;//参数复制一份到new中
  //   news.c_lflag &= ~( ECHO | ICANON);//修改new中的ECHO和ICANON参数，使new不
//   tcsetattr(0,TCSANOW,&news);//将修改后的new设置为stdin的新的参数,并且立即 
    printf("请输入密码\n");

   fp=fopen("user.txt","at+");

  fprintf(fp,"%s",name);//以字符串的形式写入
       while((ch=getch2())!='\r')
   {
      if(ch=='\n')
          break;
   if(ch==BACKSPACE)
      {
          if(i>0)
          {
//                 tcsetattr(0, TCSANOW, &news);
                 pas[i--]='\0';
                 putchar('\b');
                  putchar(' ');
                  putchar('\b');
                continue;
          }
          else
          {
              printf("\a");
              continue;
          }
       }
      else 
      {
   //     tcsetattr(0, TCSANOW, &old);
        pas[i++]=ch;
          printf("*");//在回显状态下输出*
       }
   }
   pas[i]='\0';
     fprintf(fp,"%s",pas);
    fclose(fp);//关闭文件,强制将缓冲区的数据输入
    system("gzexe user.txt");
    system("rm  -rf user.txt~");  
    login();//注册完成之后转入登陆界面
}
void login()
{
    system("clear");
    system("gzexe  -d user.txt");
    system("rm  -rf user.txt~");      
    printf("登陆界面\n");
    printf("--------------\n");
     printf("请输入账号\n");
     scanf("%s",name);
     s=strlen(name);
    printf("请输入密码\n");
    struct termios old,news;//old保存当前的终端参数，new用来保存修改后的终端
   tcgetattr(0,&old);//将tcgetattr()获取到的stdin参数存到old中
   news=old;//参数复制一份到new中
   news.c_lflag &= ~( ECHO | ICANON);//修改new中的ECHO和ICANON参数，使new不回显
   tcsetattr(0,TCSANOW,&news);//将修改后的new设置为stdin的新的参数,并且立即生效 
   char text[80];
   int flag=0;
   int i=0;
   int p=0;
  setbuf(stdin, NULL);  
   scanf("%s",pas);
   strcat(name,pas);//将字符合并
   p=strlen(name);
    FILE *fp = fopen("user.txt", "r");
    if(NULL == fp)
    {
        printf("failed to open user.txt");

    }
     while(!feof(fp))
    {
        memset(text, 0, sizeof(text)); 
         setbuf(stdin, NULL);
            fseek(fp,i,SEEK_SET);
   i++;
       fgets(text,p+1,fp);
        if(strcmp(name,text)==0)
        {//判断字符是否相等
           flag=1;
           break;
        }
    }
    if(flag==1)
    {
       system("clear");
        printf("成功登陆\n");
        tcsetattr(0, TCSANOW, &old);//登陆成功后恢复原有终端参数，正常回显
        fclose(fp);
        passwd1();
    }
    else
    { printf("\n登陆失败,重新输入");
        tcsetattr(0, TCSANOW, &old);//登陆成功后恢复原有终端参数，正常回显
      fclose(fp); 
       login();
    }  
    tcsetattr(0, TCSANOW, &old);//登陆成功后恢复原有终端参数，正常回显
   system("gzexe user.txt");
     system("rm  -rf user.txt~"); 
}

void passwd1()
{

    printf("1.修改密码,2.继续，3.退出\n");
    int menu;
    int p=0;
    scanf("%d",&menu);
    switch(menu)
    {
      case 1 :{  printf("输入新密码\n");
                  char tmppw[10],tmppw2[10];
                  scanf("%s",tmppw);
                  printf("请再次输入新密码\n");
                  scanf("%s",tmppw2);
                  p=strlen(tmppw);
                  if(strcmp(tmppw,tmppw2)==0)
                  {   FILE * fp=fopen("user.txt","r+");
                       fseek(fp,s,0);
                       fwrite(tmppw,p,1,fp);
                       fclose(fp);
                       printf("密码修改成功,请重新登陆\n");
                       login();
                       break;
                   }
                   else
                   {
                       printf("两个输入的密码不一致，密码修改失败");
                       break;
                   }
              }
      case 2:{ 
               setbuf(stdin,NULL);
                 system("gcc 管理.c  o 管理");
                        system("./管理");
                        break;
             }
      case 3: {
                system("gzexe user.txt");
             system("rm  -rf user.txt~"); 
                  exit(0);
             }
      }
}
void print(int flag)
{
    int i=0;
    char map[5][100]={
        "\033[35m          欢迎来到企业人事管理系统          \n",
        "\033[34m                            \n",
        "\033[35m               我已经注册过          \n",
        "\033[35m               我是新用户             \n   ",
        "\033[35m            退出系统             \033[37m\n",
   };
    for(i=0;i<5;i++)
    {

        if(i==flag)
            printf("-->");
        else
            printf("  ");
         printf("%s",map[i]);
    }
}
int main()
{
    system("clear");
    int flag=1;
    int num=0;
    int i=0;
       do{                  
            print(flag);
    int *get=(int *)malloc(SIZE);
   while(1)      
   {  
          get[i]=getch1();
              if(get[i]=='\n')
                break;
       if(get[i]==0x41)
            {   num--;
                flag--;
                system("clear");
                 print(flag);
            }
           if(get[i]==0x42)
            {  num++;
              flag++;
              system("clear");
              print(flag);
            }
           i++;
    }
   free(get);
       switch(num)
       {
         case 1: {
                     login();
                 break;
                 };
         case 2:{
                  regist();
                 break;
                }
        case 3:
                 exit(0);

    }
       }while(num<=2||num>=0);
    return 0;
}

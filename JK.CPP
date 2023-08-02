#include<iostream.h>
#include<conio.h>
#include <graphics.h>
#include<dos.h>
#include<math.h>
#include<string.h>
# include<ctype.h>
# include <stdlib.h>
# include<stdio.h>
void hid();
initmouse();
getmousepos(int,int,int,int);
getmousepos(int *,int *,int *);
restrictmouseptr(int,int,int,int);
//showmouseptr32();
//showmouseptr();

union REGS i,o;
char *name[41]={"Sin","Cos","Tan","Root","Log10","new","An10",
	      "logE","aNe","!"," Pi","new"," %"," xpY","1/x",
	      " #CLS",". ","new"," 1"," 2"," 3"," (  "," +",
	      "new"," 4"," 5 "," 6"," ) "," -","new"," 7"," 8",
	      " 9","   "," *","new"," 0","ANS","  ","  "," /"};
int scox[41];
int scoy[41];
	      double deg(double m)
     {
double d;
d=((double)(22)/7)*(m/180);
return(d);
}
void ftos(double m,char *p)
{
long   s;
char name[11],i=0,j=0;
char x[2]={'.','\0'};
s=m;
m=m-s;
ltoa(s,p,10);
strcat(p,x);
while(m!=0)
{
m=m*10;
s=m;
if(i==5)
break;
name[i]=s+48;
m=m-s;
++i;
 }
name[i]='\0';
for(j=i-1;name[j]=='0';--j);
name[j+1]='\0';


strcat(p,name);
}
showmouseptr();
class window1
{
protected:
int wlx,wly,wrx,wry,wcl1,wcl2;
public :
window1(int lx=100,int ly=50,int rx=550,int ry=420,int co1=1,int co2=1)
{
wlx=lx;
wly=ly;
wrx=rx;
wry=ry;
wcl1=co1;
wcl2=co2;
}
void line_w(int sx,int sy)
{              showmouseptr();
line(wlx+sx,wly+sy+40,wrx-sx,wly+sy+40);
setfillstyle(1,3) ;
floodfill(wlx+sx+2,wly+sy+3,getcolor());
}
void pdraw(int sx,int sy,int k=-1)
{

setfillstyle(1,BLACK);//wcl1);
bar(wlx+1,wly+1,wrx-1,wry-1);
rectangle(wlx+sx/2,wly+sy/2,wrx-(3*sx)/2,wry-(3*sy)/2);
setfillstyle(1,LIGHTRED);//wcl2);
bar(wlx+sx/2+1,wly+sy/2+1,wrx-(3*sx)/2-1,wry-(3*sy)/2-1);
if(k!=-1)
outtextxy(wlx+sx/2,wly+sy/2+4,name[k]);

line(wlx,wly,wlx+sx/2,wly+sy/2 );
line(wrx,wry,wrx-(3*sx)/2,wry-(3*sy)/2 );
line(wlx,wry,wlx+sx/2,wry-(3*sy)/2 );
line(wrx,wly,wrx-(3*sx)/2,wly+(sy)/2 );
delay(400);
}
void push_but(int sx,int sy)
{
setbkcolor(1);
draw( sx, sy);

//getch();
pdraw(sx,sy);
draw(sx,sy);
getch();

}
void draw(int sx,int sy)
{
setfillstyle(1,LIGHTBLUE);//wcl1);
rectangle(wlx,wly,wrx,wry);
bar(wlx+1,wly+1,wrx-1,wry-1);

setfillstyle(1,wcl2);
rectangle(wlx+sx,wly+sy,wrx-sx,wry-sy);
setfillstyle(1,wcl2);
bar(wlx+sx+1,wly+sy+1,wrx-sx-1,wry-sy-1);
line(wlx,wly,wlx+sx,wly+sy );
line(wrx,wry,wrx-sx,wry-sy );
line(wlx,wry,wlx+sx,wry-sy );
line(wrx,wly,wrx-sx,wly+sy );
setfillstyle(1,wcl2);

}
};
class button:public window1
{ //showmouseptr();
public :
void dbutton();
void getdata();
void pbutton(int k);
};

void button::getdata()
{
char c;
union REGS regsi,regso;
int b,x,y;
double value[10],d;
char s[100];
char stack[10];
int mu=1,muk;
int dwx=520,s_top=-1;
int k,i=0,vp=-1,check=0;
 s[0]='0';
 s[1]='\0';

settextstyle(1,0,1);
setfillstyle(1,3);
settextstyle(1,1,3);
outtextxy(15,150,"Compiled ");
outtextxy(40,180,"BY");
settextstyle(1,0,1);
outtextxy(250,20,"CALCULATOR");
settextstyle(1,1,1);
outtextxy(570,150,"Junaid khan");
//outtextxy(570,240,"");
settextstyle(1,0,1);
outtextxy(155,420,"CAPITAL LETTERS ARE HOT KEYS");
outtextxy(155,450,"PRESS ESC TO EXIT");
 bar(dwx-15,80,529,109);
outtextxy(520,80,s);
//    showmouseptr32();

while(1)
{
muk=0;
c=123;
//    showmouseptr32();
showmouseptr();
getmousepos(&b,&x,&y);

if(b==1)
{
gotoxy(60,1);
cout<<"           ";
gotoxy(60,1);

cout<<x<<"  "<<y;

}
if(b==1)
{
//hid();
	if((x>=156&&x<=202)&&(y>=127 && y<=145))
	c='s';
	if((x>=230&&x<=271)&&(y>=127 && y<=145))
	c='c';
	if((x>=299&&x<=342)&&(y>=127 && y<=145))
	c='t';
	if((x>=369&&x<=410)&&(y>=127 && y<=145))
	c='r';
	if((x>=439&&x<=481)&&(y>=127 && y<=145))
	c='l';
	if((x>=156&&x<=202)&&(y>=167 && y<=186))
	c='a';
	if((x>=230&&x<=271)&&(y>=167 && y<=186))
	c='e';
	if((x>=299&&x<=342)&&(y>=167 && y<=186))
	c='n';
	if((x>=369&&x<=410)&&(y>=167 && y<=185))
	c='!';
	if((x>=439&&x<=481)&&(y>=167 && y<=185))
	c='p';


	if((x>=156&&x<=202)&&(y>=206 && y<=225))
	c='%';
	if((x>=230&&x<=271)&&(y>=206 && y<=225))
	c='y';
	if((x>=299&&x<=342)&&(y>=206 && y<=225))
	c='x';
	if((x>=369&&x<=410)&&(y>=206 && y<=225))
	c='#';
	if((x>=439&&x<=481)&&(y>=206 && y<=225))
	c='.';
	if((x>=156&&x<=202)&&(y>=247 && y<=265))
	c='1';
		if((x>=230&&x<=271)&&(y>=247 && y<=265))
	c='2';
	if((x>=299&&x<=342)&&(y>=247 && y<=265))
	c='3';
	if((x>=369&&x<=410)&&(y>=247 && y<=265))
	c='(';
	if((x>=439&&x<=481)&&(y>=247 && y<=265))
	c='+';



if((x>=156&&x<=202)&&(y>=286 && y<=305))
	c='4';
		if((x>=230&&x<=271)&&(y>=286 && y<=305))
	c='5';
	if((x>=299&&x<=342)&&(y>=286 && y<=305))
	c='6';
	if((x>=369&&x<=410)&&(y>=286 && y<=305))
	c=')';
	if((x>=439&&x<=481)&&(y>=286 && y<=305))
	c='-';
	if((x>=156&&x<=202)&&(y>=327 && y<=345))
	c='7';
		if((x>=230&&x<=271)&&(y>=327 && y<=345))
	c='8';
	if((x>=299&&x<=342)&&(y>=327 && y<=345))
	c='9';
	if((x>=439&&x<=481)&&(y>=327 && y<=345))
	c='*';
	if((x>=156&&x<=202)&&(y>=366 && y<=385))
	c='0';
       if((x>=230&&x<=272)&&(y>=366 && y<=385))
	c=13;//ascii value of enter
   if((x>=439&&x<=481)&&(y>=366 && y<=385))
	c='/';


 }

if(kbhit())
{
c=getch();
if(c==27)
break;

if(c==0)
c=getch();

c=tolower(c);
}
if(c==123)
continue;
switch(c)
{
case 'a':
k=6;
 break;
case 'e':
k=7;
 break;
case 'n':
k=8;
 break;
case '!':
k=9;
 break;
case 'p':
k=10;
 break;
case '%':
k=12;
 break;
case 'y':
k=13;
 break;
case 'x':
k=14;
 break;
case '#':
k=15;
 break;
case '.':
k=16;
 break;

case '+':
k=22;
 break;
case '*':
k=34;
 break;
case '/':
k=40;
 break;
case '-':
k=28;
 break;
case 13:
k=37;
 break;

case 's':
k=0;
 break;
case 'c':
k=1;

 break;
case 't':
k=2;
 break;
case 'r':
k=3;
 break;
case 'l':
k=4;
 break;
 case '(':
 k=21;
 break;
 case ')':
 k=27;
 break;

case '1':
k=18;
 break;
case '2':
k=19;
 break;
case '3':
k=20;
 break;

case '4':
k=24 ;
 break;
case '5':
k=25;
 break;
case '6':
k=26  ;
 break;
case '7':
k=30;
 break;
case '8':
k=31;
 break;
case '9':
k=32;
 break;
case '0':
k=36;
 break;
 default:
 k=-1;
}
settextstyle(0,0,1);

if(k!=-1)
pbutton(k);
if(c==13)
{
if(s_top!=-1)
{
vp++;

value[vp]=atof(s);


while(s_top!=-1)
{
 if(stack[s_top]=='y')
 value[vp-1]=pow(value[vp-1],value[vp]);

if(stack[s_top]=='*')
value[vp-1]=value[vp-1]*value[vp];
if(stack[s_top]=='/')
value[vp-1]=value[vp-1]/value[vp];
if(stack[s_top]=='-')
{
value[vp-1]=value[vp-1]-value[vp];
}
if(stack[s_top]=='+')
value[vp-1]=value[vp-1]+value[vp];
s_top--;
vp--;

check=1;
}
long g=value[vp];
if(g==value[vp])
{
ltoa(g,s,10);
}
else
ftos(value[vp],s);

settextstyle(1,0,2);

setfillstyle(1,3);
int l=strlen(s);
l=530-12*l;

bar(121,80,529,109);
outtextxy(l,80,s);

getch();
}
else
{
int l=strlen(s);
l=530-12*l;
 bar(121,80,529,109);
outtextxy(l,80,s);

}

 s[0]='0';
  s[1]='\0';
 settextstyle(1,0,1);

setfillstyle(1,3);

 bar(121,80,529,109);
outtextxy(520,80,s);
dwx=520;

 i=0;
 mu=1;

 }

if(c=='s')
 {
d=atof(s);

d= deg(d);
 d=sin(d);
d=d+0.00001;

ftos(d,s);
int l=strlen(s);
l=530-12*l;
   settextstyle(1,0,1);

setfillstyle(1,3);

 bar(121,80,529,109);
outtextxy(l,80,s);

 }
 if(c=='p')
 {
//d=atof(s);

d=(double)22/(double)7;
ftos(d,s);
int l=strlen(s);
l=530-12*l;
   settextstyle(1,0,1);

setfillstyle(1,3);

 bar(121,80,529,109);
outtextxy(l,80,s);

 }

 if(c=='x')
 {
d=atof(s);

d=1/d;
ftos(d,s);
int l=strlen(s);
l=530-12*l;
   settextstyle(1,0,1);

setfillstyle(1,3);

 bar(121,80,529,109);
outtextxy(l,80,s);

 }

 if(c=='r')
 {
d=atof(s);

d=sqrt(d);
ftos(d,s);
int l=strlen(s);
l=530-12*l;
   settextstyle(1,0,1);

setfillstyle(1,3);

 bar(121,80,529,109);
outtextxy(l,80,s);

 }


if(c=='!')
{
d=atof(s);
long l1=d,i,fact=1;
for(i=1;i<=l1;++i)
fact=fact*i;
ltoa(fact,s,10);
int l=strlen(s);
l=530-12*l;
   settextstyle(1,0,1);

setfillstyle(1,3);

 bar(121,80,529,109);
outtextxy(l,80,s);

 }

 if(c=='t')
 {
d=atof(s);

d= deg(d);
 d=tan(d);
d=d+0.00001;

ftos(d,s);
int l=strlen(s);
l=530-12*l;
   settextstyle(1,0,1);

setfillstyle(1,3);

 bar(121,80,529,109);
outtextxy(l,80,s);

 }
 if(c=='l')
 {
d=atof(s);

 d=log10(d);

ftos(d,s);
int l=strlen(s);
l=530-12*l;
   settextstyle(1,0,1);

setfillstyle(1,3);

 bar(121,80,529,109);
outtextxy(l,80,s);

 }
 if(c=='e')
 {
d=atof(s);

 d=log (d);

ftos(d,s);
int l=strlen(s);
l=530-12*l;
   settextstyle(1,0,1);

setfillstyle(1,3);

 bar(121,80,529,109);
outtextxy(l,80,s);

 }

 if(c=='c')
 {
d=atof(s);

d= deg(d);
 d=cos(d);
if(d!=0)
d=d+0.00001;

ftos(d,s);
int l=strlen(s);
l=530-12*l;
   settextstyle(1,0,1);

setfillstyle(1,3);


 bar(121,80,529,109);
outtextxy(l,80,s);

 }
  if(c=='%')
 {
d=atof(s);

d= d/100;
ftos(d,s);
int l=strlen(s);
l=530-12*l;
   settextstyle(1,0,1);

setfillstyle(1,3);


 bar(121,80,529,109);
outtextxy(l,80,s);

 }

 if(c=='a')
 {
d=atof(s);
d=pow(10,d) ;
ftos(d,s);
int l=strlen(s);
l=530-12*l;
   settextstyle(1,0,1);

setfillstyle(1,3);


 bar(121,80,529,109);
outtextxy(l,80,s);

 }
 if(c=='n')
 {
d=atof(s);
d=exp(d) ;
ftos(d,s);
int l=strlen(s);
l=530-12*l;
   settextstyle(1,0,1);

setfillstyle(1,3);


 bar(121,80,529,109);
outtextxy(l,80,s);

 }

 if(c=='#')
 {
 s_top=-1;
     mu=1;
  vp=-1;
  settextstyle(1,0,1);

setfillstyle(1,3);
     s[0]='0';
     s[1]='\0';
bar(121,80,529,109);
outtextxy(520,80,s);
i=0;
  dwx=520;
  }
if(c=='(')
{
s_top++;
stack[s_top]='(';
//cout<<"            "<<s_top;

}
if(c==')')
{
if(s_top!=-1)
{
vp++;

value[vp]=atof(s);


while(s_top!=-1 && stack[s_top]!='(')
{
 if(stack[s_top]=='y')
 value[vp-1]=pow(value[vp-1],value[vp]);

if(stack[s_top]=='*')
value[vp-1]=value[vp-1]*value[vp];
if(stack[s_top]=='/')
value[vp-1]=value[vp-1]/value[vp];
if(stack[s_top]=='-')
{
value[vp-1]=value[vp-1]-value[vp];


}
if(stack[s_top]=='+')
value[vp-1]=value[vp-1]+value[vp];
s_top--;
vp--;

check=1;
}

long g=value[vp];
if(g==value[vp])
{
ltoa(g,s,10);
}
else
ftos(value[vp],s);

settextstyle(1,0,1);

setfillstyle(1,3);
int l=strlen(s);
l=530-12*l;

bar(121,80,529,109);
outtextxy(l,80,s);

stack[s_top]=c;
getch();

}
else
{
vp++;

value[vp]=atof(s);

}

 s[0]='0';
  s[1]='\0';
 settextstyle(1,0,1);

setfillstyle(1,3);

 bar(121,80,529,109);
outtextxy(520,80,s);
dwx=520;

 i=0;
mu=1;
 }

if(c=='y')
{
if(stack[s_top]=='y')
{
vp++;
value[vp]=atof(s);
value[vp-1]=pow(value[vp-1],value[vp]);
--vp;
long g=value[vp];
if(g==value[vp])
{
ltoa(g,s,10);
}
else
ftos(value[vp],s);

settextstyle(1,0,1);

setfillstyle(1,3);
int l=strlen(s);
l=530-12*l;

bar(121,80,529,109);
outtextxy(l,80,s);
outtextxy(10,10,"dilip");

getch();

}
else
{
++s_top;
stack[s_top]='y';
++vp;
value[vp]=atof(s);
}
 s[0]='0';
  s[1]='\0';
 settextstyle(1,0,1);

setfillstyle(1,3);

 bar(121,80,529,109);
outtextxy(520,80,s);
dwx=520;

 i=0;
mu=1;

}


if(c=='+'||c=='-')
{
if(s_top!=-1)
{
vp++;

value[vp]=atof(s);

int k=1;
while(s_top!=-1 &&stack[s_top]!='(')
{
 k=0;
 if(stack[s_top]=='y')
 value[vp-1]=pow(value[vp-1],value[vp]);

if(stack[s_top]=='*')
value[vp-1]=value[vp-1]*value[vp];
if(stack[s_top]=='/')
value[vp-1]=value[vp-1]/value[vp];
if(stack[s_top]=='-')
{
value[vp-1]=value[vp-1]-value[vp];


}
if(stack[s_top]=='+')
value[vp-1]=value[vp-1]+value[vp];
s_top--;
vp--;

check=1;
}
s_top++;
long g=value[vp];
if(g==value[vp])
{
ltoa(g,s,10);
}
else
ftos(value[vp],s);

settextstyle(1,0,1);

setfillstyle(1,3);
int l=strlen(s);
l=530-12*l;

bar(121,80,529,109);
outtextxy(l,80,s);

stack[s_top]=c;
//getch();

}

else
{
s_top++;
vp++;

stack[s_top]=c;
value[vp]=atof(s);

}

 s[0]='0';
  s[1]='\0';
 settextstyle(1,0,1);

setfillstyle(1,3);

 bar(121,80,529,109);
outtextxy(520,80,s);
dwx=520;

 i=0;
mu=1;
 }

if(c=='*'||c=='/')
{
if(s_top!=-1)
{
vp++;

value[vp]=atof(s);

int k=1;
while(s_top!=-1 && stack[s_top]!='(')
{       k=0;
 if(stack[s_top]=='y')
 value[vp-1]=pow(value[vp-1],value[vp]);

if(stack[s_top]=='*')
value[vp-1]=value[vp-1]*value[vp];
if(stack[s_top]=='/')
value[vp-1]=value[vp-1]/value[vp];
if(stack[s_top]=='-')
break;
if(stack[s_top]=='+')
break;
s_top--;
vp--;
check=1;

}
s_top++;
long g=value[vp];
if(g==value[vp])
{
ltoa(g,s,10);
}
else
ftos(value[vp],s);
settextstyle(1,0,1);

setfillstyle(1,3);
int l=strlen(s);
l=530-12*l;

bar(121,80,529,109);
outtextxy(l,80,s);

stack[s_top]=c;
//getch();

}
else
{s_top++;
vp++;

stack[s_top]=c;
value[vp]=atof(s);

}


 s[0]='0';
  s[1]='\0';
 settextstyle(1,0,1);

setfillstyle(1,3);

 bar(121,80,529,109);
outtextxy(520,80,s);
dwx=520;

 i=0;
mu=1;
//getch();

 }
if(c=='.' && mu==1)
{
muk=1;
mu=2;
}
if((isdigit(c)||muk==1)&&i<15)
{
settextstyle(1,0,1);

s[i]=c;
s[i+1]='\0';
++i;
setfillstyle(1,3);
bar(dwx,80,529,109);
outtextxy(dwx,80,s);
dwx=dwx-12;
//cout<<name[41];
}


}
}

void button::pbutton(int k)
{
wlx=scox[k];
wly=scoy[k];
wrx=wlx+60;
wry=wly+30;
wcl1=4;
wcl2=6;

pdraw(8,5,k);

draw(8,5);
outtextxy(wlx+10,wly+10,name[k]);


}
void button::dbutton()
{
int i,scx=150,scy=120;
wcl1=4;
wcl2=6;
for(i=0;i<41;++i)
{
if(stricmp(name[i],"new")==0)
{scy+=40;
 scx=150;
}
else
{
scox[i]=scx ;
scoy[i]=scy ;

wlx=scx;
wly=scy;
wrx=scx+60;
wry=scy+30;
if(strncmp(name[i],"   ",2)!=0)
draw(8,5);
outtextxy(scx+10,scy+10,name[i]);

scx=scx+70;
}
}
}
void main()
//void mn()
{

 showmouseptr();
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax,i=3,x,y;
  // initialize graphics and local variables
   initgraph(&gdriver, &gmode, "");
	initmouse();

	restrictmouseptr(1,1,getmaxx(),getmaxy());
    showmouseptr();
   setfillstyle(2,5);
   floodfill(200,200,getcolor());
   outtextxy(410,430,"Press Enter");
   showmouseptr();
   getch();
//hid();
   cleardevice();
window1 s;
button b;
int gd=DETECT,gm;
initgraph(&gd,&gm,"d:\\tc++\turboc3\bgi");
s.draw(20,20);
s.line_w(20,20);
b.dbutton();

b.getdata();
getch();
closegraph();

}

     // initialise mouse

     initmouse()
     {
       i.x.ax=0;
       int86(0x33,&i,&o);
       return(o.x.ax);
     }

     //displays mouse pointer

     showmouseptr()
     {
       i.x.ax=1;
       int86(0x33,&i,&o);
       return 0;
     }
  showmouseptr32()
     {
       i.x.ax=1;
       int86(0x33,&i,&o);
       return 0;
     }
     void hid()
     {
      i.x.ax=2;
       int86(0x33,&i,&o);

     }


     //restricts mouse movement

     restrictmouseptr(int x1,int y1,int x2,int y2)
     {
       i.x.ax=7;
       i.x.cx=x1;
       i.x.dx=x2;
       int86(0x33,&i,&o);
       i.x.ax=8;
       i.x.cx=y1;
       i.x.dx=y2;
       int86(0x33, &i,&o);

       return 0;
      }

       //get mouse coordination

       getmousepos(int *button,int *x,int *y)
       {
	  i.x.ax=3;
	  int86(0x33,&i,&o);
	  *button=o.x.bx;
	  *x=o.x.cx;
	  *y=o.x.dx;
	   return 1;
       }


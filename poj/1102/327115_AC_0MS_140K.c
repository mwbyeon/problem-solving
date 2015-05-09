#include <stdio.h>
#include <string.h>

void draw(char c,int n); 
void nl();                 

void main()
{
   int s,i,j,cnt;
   char array_num[10];
   
   scanf("%d",&s);
   while(s!=0)
   {
       scanf("%s",array_num);
       cnt=strlen(array_num);

       for (i=0 ; i<cnt ; i++) {
           if(array_num[i]=='1' || array_num[i]=='4') {
               draw(' ',s+2);
           }
           else {
               draw(' ',1);
               draw('-',s);
               draw(' ',1);
           }
           draw(' ',1);
       }
       nl();    


       for (j=0 ; j<s ; j++) {
           for (i=0 ; i<cnt ; i++) {
               if(array_num[i]=='5' || array_num[i]=='6') {
                   draw('|',1);
                   draw(' ',s);
                   draw(' ',1);
               }   else
               if(array_num[i]=='4' || array_num[i]=='8' || array_num[i]=='9' || array_num[i]=='0') {
                   draw('|',1);
                   draw(' ',s);
                   draw('|',1);
               }
               else {                
                   draw(' ',1);
                   draw(' ',s);
                   draw('|',1);
               }
           draw(' ',1);  
           }
           nl();
       }
   

       for (i=0 ; i<cnt ; i++) {
           if(array_num[i]=='1' || array_num[i]=='7' || array_num[i]=='0')
               draw(' ',s+2);
           else {
               draw(' ',1);
               draw('-',s);
               draw(' ',1);
           }
           draw(' ',1); 
       }
       nl();   
   

       for (j=0 ; j<s ; j++) { 
           for (i=0 ; i<cnt ; i++) {
               if(array_num[i]=='2') {
                   draw('|',1);
                   draw(' ',s);
                   draw(' ',1);
               }   
               else
               if(array_num[i]=='6' || array_num[i]=='8' ||array_num[i]=='0') {
                   draw('|',1);
                   draw(' ',s);
                   draw('|',1);
               }
               else {                
                   draw(' ',1);
                   draw(' ',s);
                   draw('|',1);
               }
               draw(' ',1);
           }
       nl();
       }


       for (i=0 ; i<cnt ; i++) {
           if(array_num[i]=='1' || array_num[i]=='4' || array_num[i]=='7')
               draw(' ',s+2);
           else {
               draw(' ',1);
               draw('-',s);
               draw(' ',1);
           }
           draw(' ',1); 
       }
       nl();
       nl();
       scanf("%d",&s);
   }
}

void draw(char c, int n) {
   while(n-->0)
       printf("%c",c);
}

void nl() {
   printf("\n");
}
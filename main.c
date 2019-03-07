#include <stdio.h>
#include <stdlib.h>


struct client{
    int stackSize;
    int quequeSize;
    int front;
    int rear;
    int top;
    char* stack;
    char* queque;
    char* history;
    int historytop;
};


int main(int argc,char *argv[])
{

    FILE *file,*file2;
    FILE *outputfile=fopen(argv[3],"w");
    file = fopen(argv[1], "r");
    file2=fopen(argv[2], "r");
    int lineNumber=0;
    struct client serv;//important

    int count = 0,count1=0,clientCount=0;
    int inte;
     if ( file != NULL )
        {
    char line1[256];
    while (fgets(line1, sizeof line1, file) != NULL)
    {
        if (count1 == 0)
        {
            if(sscanf(line1,"%d",&inte)==1){
            }

           // printf(line1);

        }
        else{

        }
        count1++;
    }
        }


    struct client cent[inte-1];
    int i1,i2;
    rewind(file);
    if ( file != NULL )
        {
    char line[256];
    while (fgets(line, sizeof line, file) != NULL)
    {
        if (count == lineNumber)
        {

        }

        else if(count==count1-1){
           if(sscanf(line,"%d %d",&i1,&i2)==2){


           // printf("%d",i1);
            serv.stackSize=i2;
            serv.quequeSize=i1;
           } //    printf("%s",first);

        }
        else
        {

            int i3,i4;
            if(sscanf(line,"%d %d",&i3,&i4)==2){


            cent[clientCount].stackSize=i4;
            cent[clientCount].quequeSize=i3;
            //printf("%d\n", cent[clientCount].stackSize);

            clientCount++;
          //  printf("%d ",i3);
         }  // printf("%s",first);
        }
        count++;
    }


    fclose(file);

}

for(lineNumber=0;lineNumber<inte-1;lineNumber++){
    makeArray(&cent[lineNumber],cent[lineNumber].stackSize,cent[lineNumber].quequeSize);
}
/*for(lineNumber=0;lineNumber<inte-1;lineNumber++){
    printf("%d ",cent[lineNumber].quequeSize);
}*/
serv.stackSize=i2;
serv.top=-1;
serv.front=-1;
serv.rear=-1;
serv.quequeSize=i1;
serv.stack=((char*)malloc(i2*sizeof(char)));
serv.queque=((char*)malloc(i1*sizeof(char)));
serv.historytop=-1;
 int fst;
int num=0;
if ( file2 != NULL )
        {
    char buf[999];
    char a1,a2,a3;
    int k1;

    while (fgets(buf, sizeof buf, file2) != NULL) {

        if(num==0){
            if(sscanf(buf,"%d",&fst)==1){

           serv.history=((char*)malloc(fst*sizeof(char)));
           int nume;
           for(nume=0;nume<inte-1;nume++){
            cent[nume].history=((char*)malloc(fst*sizeof(char)));
           }
           }
        }
        else{
            if(sscanf(buf,"%c %d %c",&a1,&k1,&a2)==3){
                    if(a1=='A'){
                       // printf("a");
                        if(quequeisFull(&cent[k1-1])==1){
                            appendArray(&cent[k1-1],'1');
                           // printf("1");
                        }
                        else{
                        //printf("gecti");

                        equeque(&cent[k1-1],a2);

                        }
                    }
                 else if(a1=='I'){
                        if(k1==inte){

                            if(stackisFull(&serv)==1){
                                    appendArray(&serv,'2');
                               // printf("2");
                            }
                            else{

                                push(&serv,a2);
                            }
                        }
                        else{

                            if(stackisFull(&cent[k1-1])==1){
                                appendArray(&cent[k1-1],'2');
                                //printf("2");
                            }
                            else{
                                push(&cent[k1-1],a2);
                            }
                        }
                    }
            else if(a1=='S'){
                if(stackisEmpty(&cent[k1-1])==1){
                    if(quequisEmpty(&cent[k1-1])==1){
                        appendArray(&cent[k1-1],'3');
                       // printf("3");
                    }
                    else{
                        if(quequeisFull(&serv)==1){
                            appendArray(&serv,'1');
                                //printf("1");
                            appendArray(&cent[k1-1],cent[k1-1].queque[cent[k1-1].front]);
                               // printf("%c",cent[k1-1].queque[cent[k1-1].front]);
                                dequeque(&cent[k1-1]);
                            //ignore
                        }
                        else{
                            equeque(&serv,cent[k1-1].queque[cent[k1-1].rear]);
                            appendArray(&cent[k1-1],cent[k1-1].queque[cent[k1-1].front]);
                            // printf("%c",cent[k1-1].queque[cent[k1-1].front]);
                            dequeque(&cent[k1-1]);
                        }
                    }
                }
                else{
                    if(quequeisFull(&serv)==1){
                            appendArray(&serv,'1');
                       // printf("1");//ignorep
                    appendArray(&cent[k1-1],cent[k1-1].stack[cent[k1-1].top]);
                       // printf("%c",cent[k1-1].stack[cent[k1-1].top]);
                        pop(&cent[k1-1]);

                      //  pop(&cent[k1-1]);
                    }
                    else{
                        equeque(&serv,cent[k1-1].stack[cent[k1-1].top]);
                        appendArray(&cent[k1-1],cent[k1-1].stack[cent[k1-1].top]);
                        // printf("%c",cent[k1-1].stack[cent[k1-1].top]);
                        pop(&cent[k1-1]);
                    }
                }

            }
               // printf("%c ",a1);
            }
                //printf("2");
           else if(sscanf(buf,"%c %c %c",&a1,&a2,&a3)==3){
                if(a1=='O'){
                    if(stackisEmpty(&serv)==1){
                        if(quequisEmpty(&serv)==1){
                                appendArray(&serv,'3');
                           // printf("3");
                        }
                        else{
                            appendArray(&serv,serv.queque[serv.front]);
                       // printf("%c",serv.queque[serv.front]);
                        dequeque(&serv);
                        }
                    }
                    else{
                            appendArray(&serv,serv.stack[serv.top]);
                       // printf("%c",serv.stack[serv.top]);
                        pop(&serv);
                    }
                }
           }
        }
        num++;
        }
        }


    int o=serv.historytop;
    int clients;
    for(clients=0;clients<inte-1;clients++){
        int sizes=cent[clients].historytop;
        for(sizes;sizes<fst;sizes++){
            appendArray(&cent[clients],' ');
        }
    }
    int p;
    for(clients=0;clients<inte-1;clients++){
        fprintf(outputfile,"Client %d = ",clients+1);
       // printf("Client %d = ",clients+1);
        for(p=0;p<fst;p++){
            fprintf(outputfile,"%c ",cent[clients].history[p]);
           // printf("%c ",cent[clients].history[p]);
        }
        fprintf(outputfile,"\n");
        //printf("\n");
    }
    for(o;o<fst;o++){
        appendArray(&serv,' ');
    }
    fprintf(outputfile,"Server History = ");
   // printf("Server History = ");
    for(p=0;p<fst;p++){
        fprintf(outputfile,"%c ",serv.history[p]);
        //printf("%c ",serv.history[p]);
    }
    free(serv.stack);
    free(serv.queque);
    free(serv.history);
    int l;
    for(l=0;l<inte-1;l++){
        free(cent[l].stack);
        free(cent[l].queque);
        free(cent[l].history);
    }
    fclose(file2);
    fclose(outputfile);
    return 0;

}

void makeArray(struct client* c,int csize,int qsize){

    c->stack=((char*)malloc(csize*sizeof(char)));
    c->queque=((char*)malloc(qsize*sizeof(char)));
    c->rear=-1;
    c->front=-1;
    c->top=-1;
    c->historytop=-1;
}
int stackisEmpty(struct client* c){
    if(c->top==-1){
        return 1;
    }
    else{
        return 0;
    }


}

int stackisFull(struct client* c){
    if(c->top==((c->stackSize)-1)){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct client* c,char a){

    c->top++;
    c->stack[c->top]=a;
}
void pop(struct client* c){
      c->top--;


         }
int quequisEmpty(struct client* c){
    if(c->rear==-1 && c->front==-1){

        return 1;
    }

    else{
        return 0;
    }
}
void equeque(struct client* c,char ch){
    if(quequisEmpty(c)==1){

        c->rear=0;
        c->front=0;
        c->queque[c->rear]=ch;
    }
    else{
    c->rear=(((c->rear)+1)%c->quequeSize);
    c->queque[c->rear]=ch;
    }


}

void dequeque(struct client* c){
    if(c->front==c->rear){
        c->front=-1;
        c->rear=-1;
    }
    else{
    c->front=(((c->front)+1)%c->quequeSize);
    }
}
int quequeisFull(struct client* c){
    if(c->front==0 && c->rear==c->quequeSize){
        return 1;
    }
    else if(((c->rear)+1)%c->quequeSize==c->front){

        return 1;
    }
    else{
        return 0;
    }
}
void appendArray(struct client* c,char a){
        c->historytop++;
        c->history[c->historytop]=a;
}













 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
void movefinder(char board[][8][2],char turn,char nturn);//peida kardan harekat mojaz
int changeboard(char boardcpy[][8][2],int i,int j,char turn,char nturn);//taqir board baad az har marhale
//int nextboard(char boardcpy[][][2]);
void strategy(char board[][8][2],char boardcpy[][8][2],int *xptr,int *yptr);//asl bazi
#define you '1'//khaneye siyah ke maeem =1
#define rival '2'//khaneye sefid harif=2
int main(int argc, char const *argv[])
{
    int x,y;
    x=0;
    y=0;
    int *xptr,*ypter;
    xptr=&x;
    ypter=&y;
    //srand(time(NULL));
    char board[8][8][2];//board bazi
    char boardcpy[8][8][2];//copy board bara sanjesh taqiirat
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j][1]=argv[i+1][j];//roye bazi
            board[i][j][0]='0';//roye zirin baraye tayiin emkan harekat 1 baraye valid
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            boardcpy[i][j][1]=board[i][j][1];
        }
    }//copy kardan board baraye taqirat;
    movefinder(board,you,rival);
    strategy(board,boardcpy,xptr,ypter);
    printf("%d %d",*xptr,*ypter);
    /*while(1){
        x=rand()%8;
        y=rand()%8;
        if(board[y][x][0]=='1'){
            printf("%d %d",x,y);
            break;
        }
    }*/

    /*for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%c",board[i][j][1]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){

            printf("%c",board[i][j][0]);
        }
        printf("\n");
    }*/
    return 0;
}
void movefinder(char board[][8][2],char turn,char nturn){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j][1]=='0'||board[i][j][1]==nturn){
                continue;
            }//qat halqe dar soorat khalibodan ya da dast harif bodan khane
            else{/*pas khane 1 yani khodi ast*/
                if(board[i][j+1][1]==nturn){
                    /*search harekat mojaz darsamt rast*/
                    for(int k=j+2;k<8;k++){
                        if(board[i][k][1]==turn){
                            break;
                        }//khoroj az halqeye search dar soorat residan be khaye khodi
                        else if(board[i][k][1]=='0'){
                            board[i][k][0]='1';
                            break;
                        }//moshakhas kardan harekat mojaz dar sooret residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i][j-1][1]==nturn&&j>0){
                    /*search harekat mojaz darsamt chap*/
                    for(int k=j-2;k>=0;k--){
                        if(board[i][k][1]==turn){
                            break;
                        }//khoroj az halqeye search dar soorat residan be khaneye khodi
                        else if(board[i][k][1]=='0'){
                            board[i][k][0]='1';

                            break;
                        }//moshakhas kardan harekat mojaz dar sooret residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i-1][j][1]==nturn){
                    /*search harekat mojaz darsamt bala*/
                    for(int t=i-2;t>=0;t--){
                        if(board[t][j][1]==turn){
                            break;
                        }//khoroj az halqeye search dar soorat residan be khaye khodi
                        else if(board[t][j][1]=='0'){
                            board[t][j][0]='1';
                            break;
                        }//moshakhas kardan harekat mojaz dar sooret residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i+1][j][1]==nturn){
                    /*search harekat mojaz darsamt payin*/
                    for(int t=i+2;t<8;t++){
                        if(board[t][j][1]==turn){
                            break;
                        }//khoroj az halqeye search dar soorat residan be khaye khodi
                        else if(board[t][j][1]=='0'){
                            board[t][j][0]='1';
                            break;
                        }//moshakhas kardan harekat mojaz dar sooret residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i-1][j-1][1]==nturn){
                    /*search harekate mojaz dar goosheye bala chap*/
                    int t,k;
                    for(t=i-2,k=j-2;t>=0&&k>=0;t--,k--){
                        if(board[t][k][1]==turn){
                            break;
                        }//khoroj az halqe dar soorate residan be halqeye khodi
                        else if(board[t][k][1]=='0'){
                            board[t][k][0]='1';
                            break;
                        }//moshakhas kardan harekate mojaz dar soorete residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i-1][j+1][1]==nturn){
                    /*search harekate mojaz dar goosheye bala rast*/
                    int t,k;
                    for(t=i-2,k=j+2;t>=0&&k<8;t--,k++){
                        if(board[t][k][1]==turn){
                            break;
                        }//khoroj az halqe dar soorate residan be halqeye khodi
                        else if(board[t][k][1]=='0'){
                            board[t][k][0]='1';
                            break;
                        }//moshakhas kardan harekate mojaz dar soorete residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i+1][j+1][1]==nturn){
                    /*search harekate mojaz dar goosheye payin rast*/
                    int t,k;
                    for(t=i+2,k=j+2;t<8&&k<8;t++,k++){
                        if(board[t][k][1]==turn){
                            break;
                        }//khoroj az halqe dar soorate residan be halqeye khodi
                        else if(board[t][k][1]=='0'){
                            board[t][k][0]='1';
                            break;
                        }//moshakhas kardan harekate mojaz dar soorete residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i+1][j-1][1]==nturn){
                    /*search harekate mojaz dar goosheye payin chap*/
                    int t,k;
                    for(t=i+2,k=j-2;t<8&&k>=0;t++,k--){
                        if(board[t][k][1]==turn){
                            break;
                        }//khoroj az halqe dar soorate residan be halqeye khodi
                        else if(board[t][k][1]=='0'){
                            board[t][k][0]='1';
                            break;
                        }//moshakhas kardan harekate mojaz dar soorete residan be khaneye khali va khoroj az halqe
                    }
                }                                                                                  
            }

        }
    }
    return;
}
int changeboard(char boardcpy[][8][2],int i, int j,char turn,char nturn){
    //azinja
    int counter=0;//shomarandeye tedad mohrehaye taqiir karde
    int temp=0;//komaki baraye afzayesh shomarande
    if(boardcpy[i][j+1][1]==nturn){/*tashkhis inke aya bayad be rast harekat konim*/        
        for(int k=j+1;k<8;k++){
            if(boardcpy[i][k][1]==nturn){
                boardcpy[i][k][1]=turn;
                temp++;
            }//bargardandan khanehaye bein va afzayesh shomarande
            else  if(boardcpy[i][k][1]==turn){
                break;
            }//payan halqe dar soorat residan be khaneye khodi
            else{
                temp=0;
                break;
            }//payan halqe dar soorate residan be khaneye khali va 0 kardan shomarande chon ke masir qalat boode
            if(k==7){
                temp=0;
                break;
            }//payan halqe dar soorate residan be enteha va 0 kardan shomarande chon ke masir qalat boode
        }
        counter=counter+temp;//afzayesh shomarende
        temp=0;//sefr kardan shomarandeye movaqat 
    }
    if(boardcpy[i][j-1][1]==nturn){//harekat be chap?
        for(int k=j-1;k>=0;k--){
            if(boardcpy[i][k][1]==nturn){
                boardcpy[i][k][1]=turn;
                temp++;
            }//bargardandan kanehaye bein va afzayesh shomarande
            else  if(boardcpy[i][k][1]==turn){
                break;
            }//payan halqe ba residan be khaneye khodi
            else{
                temp=0;
                break;
            }//payan halqe dar soorate residan be khaneye khali va 0 kardan shomarande chon ke masir qalat boode
            if(k==0){
                temp=0;
                break;
            }//payan halqe dar soorate residan be enteha va 0 kardan shomarande chon ke masir qalat boode
        }
        counter=counter+temp;//afzayesh shomarande
        temp=0;//0 kardan shomarande movaqat baraye baad
    }
    if(boardcpy[i-1][j][1]==nturn){//aya harekat be bala?
        for(int t=i-1;t>=0;t--){
            if(boardcpy[t][j][1]==nturn){
                boardcpy[t][j][1]=turn;
                temp++;
            }//mesl qabl
            else  if(boardcpy[t][j][1]==turn){
                break;
            }//mesl qabl
            else{
                temp=0;
                break;
            }//mesl qabl
            if(t==0){
                temp=0;
                break;
            }//mesl qabl
        }
        counter=counter+temp;//mesl qabl
        temp=0;//mesl qabl
    }
    if(boardcpy[i+1][j][1]==nturn){//aya harekat be paiin
        for(int t=i+1;t<8;t++){
            if(boardcpy[t][j][1]==nturn){
                boardcpy[t][j][1]=turn;
                temp++;
            }//mesl qabl
            else  if(boardcpy[t][j][1]==turn){
                break;
            }//mesl qabl
            else{
                temp=0;
                break;
            }//mesl qabl
            if(t==7){
                temp=0;
                break;
            }//mesl qabl
        }
        counter=counter+temp;//mesl qabl
        temp=0;//mesl qabl
    }
    if(boardcpy[i-1][j-1][1]==nturn){//aya harekat be gooshe chap bala
        int t,k;
        for( t=i-1,k=j-1;t>=0&&k>=0;t--,k--){
            if(boardcpy[t][k][1]==nturn){
                boardcpy[t][k][1]=turn;
                temp++;
            }//mesl qabl
            else  if(boardcpy[t][k][1]==turn){
                break;
            }//mesl qabl
            else{
                temp=0;
                break;
            }//mesl qabl
            if(t==0||k==0){
                temp=0;
                break;
            }//mesl qabl
        }
        counter=counter+temp;//mesl qabl
        temp=0;//mesl qabl
    }
    if(boardcpy[i-1][j+1][1]==nturn){//aya harekat be gooshe bala rast
        int t,k;
        for( t=i-1,k=j+1;t>=0&&k<8;t--,k++){
            if(boardcpy[t][k][1]==nturn){
                boardcpy[t][k][1]=turn;
                temp++;
            }//mesl qabl
            else  if(boardcpy[t][k][1]==turn){
                break;
            }//mesl qabl
            else{
                temp=0;
                break;
            }//mesl qabl
            if(t==0||k==7){
                temp=0;
                break;
            }//mesl qabl
        }
        counter=counter+temp;//mesl qabl
        temp=0;//mesl qabl
    }
    if(boardcpy[i+1][j-1][1]==nturn){//aya harekat be gooshe paiin chap
        int t,k;
        for( t=i+1,k=j-1;t<8&&k>=0;t++,k--){
            if(boardcpy[t][k][1]==nturn){
                boardcpy[t][k][1]=turn;
                temp++;
            }//mesl qabl
            else  if(boardcpy[t][k][1]==turn){
                break;
            }//mesl qabl
            else{
                temp=0;
                break;
            }//mesl qabl
            if(t==7||k==0){
                temp=0;
                break;
            }//mesl qabl
        }
        counter=counter+temp;//mesl qabl
        temp=0;//mesl qabl
    }
    if(boardcpy[i+1][j+1][1]==nturn){//aya herekat be gooshe paiin rast
        int t,k;
        for( t=i+1,k=j+1;t<8&&k<8;t++,k++){
            if(boardcpy[t][k][1]==nturn){
                boardcpy[t][k][1]=turn;
                temp++;
            }//mesl qabl
            else  if(boardcpy[t][k][1]==turn){
                break;
            }//mesl qabl
            else{
                temp=0;
                break;
            }//mesl qabl
            if(t==7||k==7){
                temp=0;
                break;
            }//mesl qabl
        }
        counter=counter+temp;//mesl qabl
        temp=0;//mesl qabl
    }
    return counter;
}
/*int nextboard(char boardcpy[][8][2]){
    int counter=0;
    int temp=0;
    movefinder()
}*/
void strategy(char board[][8][2],char boardcpy[][8][2],int *xptr,int *yptr){
    int counteryou=0;//baraye shemordan teded mohrehayii ke ba har harekate ma taqir mikonad
    int counterrival=0;//baraye shemordan teded mohrehayii ke ba har harekate harid taqir mikonad
    int maxrival=0;//max tedad mohrehayi ke harif mitavanad taqir dahad
    int result=-64;//baraye mohasebeye tafazol emtiaz ma va harif
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){//chek kardan tak tak khaneha
        //printf("r");
            if(board[i][j][0]=='1'){//shart baraye anjam taqirat dar soorat residan be harekat mojaz
            //printf("ra");
                boardcpy[i][j][1]='1';//gozashtan mohreye khodi dar jaye harekat mojaz
                counteryou=changeboard(boardcpy,i,j,you,rival);//taqir dadan board va shomaresh khanehaye taqir yafte
                movefinder(boardcpy,rival,you);//peida kardan harekate mojaze harif
                for(int t=0;t<8;t++){//check kardan tak tak khanehaye harrif baad az taqiir
                //printf("raf");
                    for(int k=0;k<8;k++){
                        if(boardcpy[t][k][0]=='1'){//sharte residan be harekate mojaz
                        //printf("raft");
                            boardcpy[t][k][1]='2';//gozashtan mohreye harif dar jaye harekate mojaz
                            counterrival=changeboard(boardcpy,t,k,rival,you);//taqir dadan board va shomareshkhanehaye taqiir karde ba harekat harif

                        }
                        if(counterrival>maxrival){
                            //printf("raftt ");
                            maxrival=counterrival;
                        }//baraye tayin bishtarin emtiaze harif
                    }
                }
                //printf("m%d\n",maxrival);
                if(counteryou-maxrival>result){
                    //printf("f ");
                    result=counteryou-maxrival;
                    *xptr=j;
                    *yptr=i;
                }//baraye tayyin bishtarin tafazol va negah dashtan mokhtasat              
            }
            for(int t=0;t<8;t++){
                for(int k=0;k<8;k++){
                    boardcpy[t][k][1]=board[t][k][1];
                }
            }//bargardandan board asli be board copy

        }        
    }
    
}

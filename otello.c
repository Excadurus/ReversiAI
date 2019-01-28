 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
void movefinder(char board[][8][3],char turn,char nturn);//peida kardan harekat mojaz
void holder(char boardcpy[][8][3],char boardhold[][8],int option);//0 yani board bere to hold;
int changeboard(char boardcpy[][8][3],int i,int j,char turn,char nturn);//taqir board baad az har marhale
void MoveChoose(char board[][8][3],int *x,int *y);//vazn bazi strategy avalie
void strategy(char board[][8][3],char boardcpy[][8][3],int *xptr,int *yptr,char you,char rival);//asl bazi
int ChangeStrategy(char board[][8][3]);
int main(int argc, char const *argv[])
{
    char you,rival;
    char board[8][8][3]; //board bazi
    char boardcpy[8][8][3];
    char weightboard[8][8]={
        {0, 7, 1, 3, 3, 1, 7, 0},
        {7, 8, 6, 5, 5, 6, 8, 7},
        {1, 6, 2, 4, 4, 2, 6, 1},
        {3, 5, 4, 0, 0, 4, 5, 3},
        {3, 5, 4, 0, 0, 4, 5, 3},
        {1, 6, 2, 4, 4, 2, 6, 1},
        {7, 8, 6, 5, 5, 6, 8, 7},
        {0, 7, 1, 3, 3, 1, 7, 0}
    };//Board's Weight, The lower the Value. The Better the move. Basically Each number is a Priority.
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j][2]=weightboard[i][j];//Laye Vazn bazi
            board[i][j][1]=argv[i+1][j];//roye bazi
            board[i][j][0]='0';//roye zirin baraye tayiin emkan harekat 1 baraye valid
        }
    }
    if(*argv[9]=='1'){
        you='1';
        rival='2';
    }
    else{
        you='2';
        rival='1';
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            boardcpy[i][j][1]=board[i][j][1];
        }
    }//copy kardan board baraye taqirat;
    int x,y;
    movefinder(board,you,rival);
    if(ChangeStrategy(board)){
        strategy(board,boardcpy,&x,&y,you,rival);
    }
    else{
        MoveChoose(board,&x,&y);
    }//baraye taqir strategy dar soorate por shodan se gooshe
    printf("%d %d",x,y);
    return 0;
}
int ChangeStrategy(char board[][8][3]){
    int c=0;
    if (board[0][0][1]!='0'){
        c++;
    }
    if (board[0][7][1]!='0'){
        c++;
    }
    if (board[7][0][1]!='0'){
        c++;
    }
    if (board[7][7][1]!='0'){
        c++;
    }
    if(c>=3){
        return 1;
    }
    else{
        return 0;
    }
}
void MoveChoose(char board[][8][3],int *x,int *y){
    int checkmax=9;//in badtarin olaviat momken ast ke az hame olaviat haye mojood dar board ham bishtar ast. dar natije 100% meghdar an avaz mishavad
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j][0]=='1' && board[i][j][2]<checkmax){//agar harkat mojaz bood va olaviat an behtar bood meghdar an jaygozin mishavad
                checkmax=board[i][j][2];//olaviat checkmax ra jadid tarin olaviat mikonad ta olaviat haye bad tar az halat konooni digar jaygozin nashavand
                *x=j;// I va J ra Baraks be X,Y midahim zira satr va sotoon dar array barakse x va y dar nemoodar amal mikonand
                *y=i;
            }
        }
    }
    return;
}
void movefinder(char board[][8][3],char turn,char nturn){
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
void holder(char boardcpy[][8][3],char boardhold[][8],int option){
    if(option==0){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                boardhold[i][j]=boardcpy[i][j][1];
            }
        }
    }
    if(option==1){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                boardcpy[i][j][1]=boardhold[i][j];
            }
        }
    }
}
int changeboard(char boardcpy[][8][3],int i, int j,char turn,char nturn){
    int counter=0;//shomarandeye tedad mohrehaye taqiir karde
    int temp=0;//komaki baraye afzayesh shomarande
    char boardhold[8][8];
    if(boardcpy[i][j+1][1]==nturn){/*tashkhis inke aya bayad be rast harekat konim*/
        holder(boardcpy,boardhold,0);        
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
                holder(boardcpy,boardhold,1);
                break;
            }//payan halqe dar soorate residan be khaneye khali va 0 kardan shomarande chon ke masir qalat boode
            if(k==7){
                holder(boardcpy,boardhold,1);
                temp=0;
                break;
            }//payan halqe dar soorate residan be enteha va 0 kardan shomarande chon ke masir qalat boode
        }
        counter=counter+temp;//afzayesh shomarende
        temp=0;//sefr kardan shomarandeye movaqat 
    }
    if(boardcpy[i][j-1][1]==nturn){//harekat be chap?
        holder(boardcpy,boardhold,0);
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
                holder(boardcpy,boardhold,1);
                break;
            }//payan halqe dar soorate residan be khaneye khali va 0 kardan shomarande chon ke masir qalat boode
            if(k==0){
                temp=0;
                holder(boardcpy,boardhold,1);
                break;
            }//payan halqe dar soorate residan be enteha va 0 kardan shomarande chon ke masir qalat boode
        }
        counter=counter+temp;//afzayesh shomarande
        temp=0;//0 kardan shomarande movaqat baraye baad
    }
    if(boardcpy[i-1][j][1]==nturn){//aya harekat be bala?
        holder(boardcpy,boardhold,0);
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
                holder(boardcpy,boardhold,1);
                break;
            }//mesl qabl
            if(t==0){
                temp=0;
                holder(boardcpy,boardhold,1);
                break;
            }//mesl qabl
        }
        counter=counter+temp;//mesl qabl
        temp=0;//mesl qabl
    }
    if(boardcpy[i+1][j][1]==nturn){//aya harekat be paiin
        holder(boardcpy,boardhold,0);
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
                holder(boardcpy,boardhold,1);
                break;
            }//mesl qabl
            if(t==7){
                temp=0;
                holder(boardcpy,boardhold,1);
                break;
            }//mesl qabl
        }
        counter=counter+temp;//mesl qabl
        temp=0;//mesl qabl
    }
    if(boardcpy[i-1][j-1][1]==nturn){//aya harekat be gooshe chap bala
        holder(boardcpy,boardhold,0);
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
                holder(boardcpy,boardhold,1);
                break;
            }//mesl qabl
            if(t==0||k==0){
                temp=0;
                holder(boardcpy,boardhold,1);
                break;
            }//mesl qabl
        }
        counter=counter+temp;//mesl qabl
        temp=0;//mesl qabl
    }
    if(boardcpy[i-1][j+1][1]==nturn){//aya harekat be gooshe bala rast
        holder(boardcpy,boardhold,0);
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
                holder(boardcpy,boardhold,1);
                break;
            }//mesl qabl
            if(t==0||k==7){
                temp=0;
                holder(boardcpy,boardhold,1);
                break;
            }//mesl qabl
        }
        counter=counter+temp;//mesl qabl
        temp=0;//mesl qabl
    }
    if(boardcpy[i+1][j-1][1]==nturn){//aya harekat be gooshe paiin chap
        holder(boardcpy,boardhold,0);
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
                holder(boardcpy,boardhold,1);
                break;
            }//mesl qabl
            if(t==7||k==0){
                temp=0;
                holder(boardcpy,boardhold,1);
                break;
            }//mesl qabl
        }
        counter=counter+temp;//mesl qabl
        temp=0;//mesl qabl
    }
    if(boardcpy[i+1][j+1][1]==nturn){//aya herekat be gooshe paiin rast
        holder(boardcpy,boardhold,0);
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
                holder(boardcpy,boardhold,1);
                break;
            }//mesl qabl
            if(t==7||k==7){
                temp=0;
                holder(boardcpy,boardhold,1);
                break;
            }//mesl qabl
        }
        counter=counter+temp;//mesl qabl
        temp=0;//mesl qabl
    }
    return counter;
}
void strategy(char board[][8][3],char boardcpy[][8][3],int *xptr,int *yptr,char you,char rival){
    int counteryou=0;//baraye shemordan teded mohrehayii ke ba har harekate ma taqir mikonad
    int counterrival=0;//baraye shemordan teded mohrehayii ke ba har harekate harid taqir mikonad
    int maxrival=0;//max tedad mohrehayi ke harif mitavanad taqir dahad
    int result=-64;//baraye mohasebeye tafazol emtiaz ma va harif
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){//chek kardan tak tak khaneha
        //printf("r");
            if(board[i][j][0]=='1'){//shart baraye anjam taqirat dar soorat residan be harekat mojaz
            //printf("ra");
                boardcpy[i][j][1]=you;//gozashtan mohreye khodi dar jaye harekat mojaz
                counteryou=changeboard(boardcpy,i,j,you,rival);//taqir dadan board va shomaresh khanehaye taqir yafte
                movefinder(boardcpy,rival,you);//peida kardan harekate mojaze harif
                for(int t=0;t<8;t++){//check kardan tak tak khanehaye harrif baad az taqiir
                //printf("raf");
                    for(int k=0;k<8;k++){
                        if(boardcpy[t][k][0]=='1'){//sharte residan be harekate mojaz
                        //printf("raft");
                            boardcpy[t][k][1]=rival;//gozashtan mohreye harif dar jaye harekate mojaz
                            counterrival =changeboard(boardcpy,t,k,rival,you);//taqir dadan board va shomareshkhanehaye taqiir karde ba harekat harif

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
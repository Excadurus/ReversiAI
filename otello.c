#include<stdio.h>
void movefinder(char board[][8][3]);//peida kardan harekat mojaz
void MoveChoose(char board[][8][3],int *x,int *y);//Entekhab Kardan Harekat Mojaz
#define you '1'//khaneye siyah ke maeem =1
#define rival '2'//khaneye sefid harif=2
int main(int argc, char const *argv[])
{
    char board[8][8][3]; //board bazi
    char weightboard[8][8]={
        {0, 7, 1, 4, 4, 1, 7, 0},
        {7, 8, 6, 5, 5, 6, 8, 7},
        {1, 6, 2, 3, 3, 2, 6, 1},
        {4, 5, 3, 0, 0, 3, 5, 4},
        {4, 5, 3, 0, 0, 3, 5, 4},
        {1, 6, 2, 3, 3, 2, 6, 1},
        {7, 8, 6, 5, 5, 6, 8, 7},
        {0, 7, 1, 4, 4, 1, 7, 0}
    };//Board's Weight, The lower the Value. The Better the move. Basically Each number is a Priority.
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j][2]=weightboard[i][j];//Laye Wazn Bazi ra be board asli enteghal midahim
            board[i][j][1]=argv[i+1][j];//roye bazi
            board[i][j][0]='0';//roye zirin baraye tayiin emkan harekat 1 baraye valid
        }
    }
    int x=0,y=0;//x , y Khorooji
    int *xptr=&x,*yptr=&y;//Pointer be X,Y baraye Function
    movefinder(board);
    MoveChoose(board,xptr,yptr);
    printf("%d %d",x,y);//Khorooji tabe, Behtarin Harkat mojood ra ba tavajoh be vazn ha chap mikonad
    return 0;
}
void MoveChoose(char board[][8][3],int *x,int *y)
{
    int checkmax=9;//in badtarin olaviat momken ast ke az hame olaviat haye mojood dar board ham bishtar ast. dar natije 100% meghdar an avaz mishavad
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(board[i][j][0]=='1' && board[i][j][2]<checkmax)//agar harkat mojaz bood va olaviat an behtar bood meghdar an jaygozin mishavad
            {
                checkmax=board[i][j][2];//olaviat checkmax ra jadid tarin olaviat mikonad ta olaviat haye bad tar az halat konooni digar jaygozin nashavand
                *x=j;// I va J ra Baraks be X,Y midahim zira satr va sotoon dar array barakse x va y dar nemoodar amal mikonand
                *y=i;
            }
        }
    }
    return;
}
void movefinder(char board[][8][3]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j][1]=='0'||board[i][j][1]==rival){
                continue;
            }//qat halqe dar soorat khalibodan ya da dast harif bodan khane
            else{/*pas khane 1 yani khodi ast*/
                if(board[i][j+1][1]==rival){
                    /*search harekat mojaz darsamt rast*/
                    for(int k=j+2;k<8;k++){
                        if(board[i][k][1]==you){
                            break;
                        }//khoroj az halqeye search dar soorat residan be khaye khodi
                        else if(board[i][k][1]=='0'){
                            board[i][k][0]='1';
                            break;
                        }//moshakhas kardan harekat mojaz dar sooret residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i][j-1][1]==rival&&j>0){
                    /*search harekat mojaz darsamt chap*/
                    for(int k=j-2;k>=0;k--){
                        if(board[i][k][1]==you){
                            break;
                        }//khoroj az halqeye search dar soorat residan be khaneye khodi
                        else if(board[i][k][1]=='0'){
                            board[i][k][0]='1';

                            break;
                        }//moshakhas kardan harekat mojaz dar sooret residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i-1][j][1]==rival){
                    /*search harekat mojaz darsamt bala*/
                    for(int t=i-2;t>=0;t--){
                        if(board[t][j][1]==you){
                            break;
                        }//khoroj az halqeye search dar soorat residan be khaye khodi
                        else if(board[t][j][1]=='0'){
                            board[t][j][0]='1';
                            break;
                        }//moshakhas kardan harekat mojaz dar sooret residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i+1][j][1]==rival){
                    /*search harekat mojaz darsamt payin*/
                    for(int t=i+2;t<8;t++){
                        if(board[t][j][1]==you){
                            break;
                        }//khoroj az halqeye search dar soorat residan be khaye khodi
                        else if(board[t][j][1]=='0'){
                            board[t][j][0]='1';
                            break;
                        }//moshakhas kardan harekat mojaz dar sooret residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i-1][j-1][1]==rival){
                    /*search harekate mojaz dar goosheye bala chap*/
                    int t,k;
                    for(t=i-2,k=j-2;t>=0&&k>=0;t--,k--){
                        if(board[t][k][1]==you){
                            break;
                        }//khoroj az halqe dar soorate residan be halqeye khodi
                        else if(board[t][k][1]=='0'){
                            board[t][k][0]='1';
                            break;
                        }//moshakhas kardan harekate mojaz dar soorete residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i-1][j+1][1]==rival){
                    /*search harekate mojaz dar goosheye bala rast*/
                    int t,k;
                    for(t=i-2,k=j+2;t>=0&&k<8;t--,k++){
                        if(board[t][k][1]==you){
                            break;
                        }//khoroj az halqe dar soorate residan be halqeye khodi
                        else if(board[t][k][1]=='0'){
                            board[t][k][0]='1';
                            break;
                        }//moshakhas kardan harekate mojaz dar soorete residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i+1][j+1][1]==rival){
                    /*search harekate mojaz dar goosheye payin rast*/
                    int t,k;
                    for(t=i+2,k=j+2;t<8&&k<8;t++,k++){
                        if(board[t][k][1]==you){
                            break;
                        }//khoroj az halqe dar soorate residan be halqeye khodi
                        else if(board[t][k][1]=='0'){
                            board[t][k][0]='1';
                            break;
                        }//moshakhas kardan harekate mojaz dar soorete residan be khaneye khali va khoroj az halqe
                    }
                }
                if(board[i+1][j-1][1]==rival){
                    /*search harekate mojaz dar goosheye payin chap*/
                    int t,k;
                    for(t=i+2,k=j-2;t<8&&k>=0;t++,k--){
                        if(board[t][k][1]==you){
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
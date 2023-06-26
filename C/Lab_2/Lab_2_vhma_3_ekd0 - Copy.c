#include <stdio.h>
#define N 10
#define M 20

void initialize_plate(float data[N][M]) {
    int i,j,sum1,sum2,sum3,sum4;
    for (i=0;i<10;i++){
        if (i==0){
            printf("Initialize row 1\n");
            for (j=1;j<19;j++){
                scanf("%f",&data[i][j]);
                sum1 = sum1 + data[i][j];
            }
            printf("\n");
            data[0][0] = sum1/18;
        }
        if (i==9){
            printf("Initialize row 10\n");
            for (j=1;j<19;j++){
                scanf("%f",&data[i][j]);
                sum2 = sum2 + data[i][j];
            }
            printf("\n");
            data[10][20] = sum2/18;
        }
        printf("Initialize row %d\n", i);
            for (j=0;j<20;j++){
                scanf("%f",&data[i][j]);
            }
        printf("\n");
    }
    for (i=1;i<19;i++){
        sum3 = sum3 + data[i][19];
    }
    data[0][19]=sum3/18;
    for (i=1;i<19;i++){
        sum3 = sum3 + data[i][0];
    }
    data[9][0]=sum4/18;
}

void print_plate(float data[N][M]) {
    int i,j;
    for (i=0;i<10;i++){
        for (j=0;j<20;j++){
            printf("%f ",data[i][j]);
        }
        printf("\n");
    }
}

void new_temp(float data[N][M]) {
    printf("new_temp\n");
}

int main(){
    float data[N][M];
    initialize_plate(data);
    print_plate(data);
    new_temp(data);
    return 0;
}
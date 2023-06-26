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
        if (i!=0 && i!=9){
            printf("Initialize row %d\n", i);
                for (j=0;j<20;j++){
                    scanf("%f",&data[i][j]);
                }
            printf("\n");
        }
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

void new_temp(float data[N][M], float maxmin[2]) {
    int i,j,max,min;
    printf("The old temperature values:\n");
    print_plate(data);
    for (i=1;i<9;i++){
        for (j=1;j<19;j++){
            data[i][j] = 0.1*(data[i-1][j-1] + data[i-1][j] + data[i-1][j+1] + data[i][j-1] + 2*data[i][j] + data[i][j+1] + data[i+1][j-1] + data[i+1][j] + data[i+1][j+1]);
            if (data[i][j]<max) {
                max = data[i][j];
            }
            if (data[i][j]<min) {
                min = data[i][j];
            }      
        }
    }
    maxmin[0] = max;
    maxmin[1] = min;
    printf("The new temperature values:\n");
    print_plate(data);
}

void normalized_temp(float data[N][M], int norm_data[N][M], float maxmin[2]){
    int i,j;
    float max,min,step;
    max = maxmin[0];
    min = maxmin[1];
    step = (max-min)/10;
    for (i=0;i<10;i++){
        for (j=0;j<20;j++){
            if (min < data[i][j] < (min+step)) {norm_data[i][j] = 0;}
            if ((min+step) < data[i][j] < 2*(min+step)) {norm_data[i][j] = 1;}
            if (2*(min+step) < data[i][j] < 3*(min+step)) {norm_data[i][j] = 2;}
            if (3*(min+step) < data[i][j] < 4*(min+step)) {norm_data[i][j] = 3;}
            if (4*(min+step) < data[i][j] < 5*(min+step)) {norm_data[i][j] = 4;}
            if (5*(min+step) < data[i][j] < 6*(min+step)) {norm_data[i][j] = 5;}
            if (6*(min+step) < data[i][j] < 7*(min+step)) {norm_data[i][j] = 6;}
            if (7*(min+step) < data[i][j] < 8*(min+step)) {norm_data[i][j] = 7;}
            if (8*(min+step) < data[i][j] < 9*(min+step)) {norm_data[i][j] = 8;}
            if (9*(min+step) < data[i][j] < max) {norm_data[i][j] = 9;}
        }
    }


}

int main(){
    float data[N][M];
    float maxmin[2];
    int norm_data[N][M];
    maxmin[0] = 0;
    maxmin[1] = 0;
    initialize_plate(data);
    new_temp(data,maxmin);
    normalized_temp(data,norm_data,maxmin);
    return 0;
}
#include<stdio.h>

void main(){
    float R,G,B;
    float Rf, Gf, Bf, W,C,M,Y,K,max;

    printf("Enter the values of R G B: ");
    scanf("%f%f%f", &R, &G, &B);

    if(R<0 || R>255){
        printf("Enter valid value for R: ");
        scanf("%f", &R);
    }
    if(G<0 || G>255){
        printf("Enter valid value for G: ");
        scanf("%f", &G);
    }
    if(B<0 || B>255){
        printf("Enter valid value for B: ");
        scanf("%f", &B);
    }

    printf("*********************************************\n");
    printf("RGB values:\n");
    printf("Red: %f\n", R);
    printf("Green: %f\n", G);
    printf("Blue: %f\n", B);
    printf("*********************************************\n");

    printf("RGB to CMY:\n");
    W = 1;
    Rf = R/255;
    Gf = G/255;
    Bf = B/255;

    C = W-Rf;
    M = W-Gf;
    Y = W-Bf;

    printf("CMY values:\n");
    printf("White: %f\n", W);
    printf("Cyan: %f\n", C);
    printf("Magenta: %f\n", M);
    printf("Yellow: %f\n", Y);
    printf("*********************************************\n");

    printf("RGB to CMYK: \n");
    if(R==0 && G==0 && B==0){
        C = 0;
        M = 0;
        Y = 0;
        K = 1;
    }
    else{
        max = Rf;
        if(Gf>max)
        max = Gf;
        if(Bf>max)
        max = Bf;

        W = max;

        C = (W-Rf)/W;
        M = (W-Gf)/W;
        Y = (W-Bf)/W;
        K = 1-W;
    }
    printf("CMYK values:\n");
    printf("Cyan: %f\n", C);
    printf("Magenta: %f\n", M);
    printf("Yellow: %f\n", Y);
    printf("Black: %f\n", K);


}
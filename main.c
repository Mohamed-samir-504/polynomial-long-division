#include <stdio.h>


struct Sx
{
 float coef;
 int power;

};

void divide(struct Sx arr_up[], struct Sx arr_down[], int n_d, int n_u)
{
    struct Sx answer[7] ={0}, mult_result[7]={0}, add_result[7]={0}, add_result2[7]={0}, add_result3[7]={0},
    add_result4[7]={0}, add_result5[7]={0},add_result6[7]={0};
    struct Sx* add[]={arr_up,add_result,add_result2,add_result3,add_result4,add_result5,add_result6};
    int n=0, k = 1, z;
    //division step
    answer[n].coef = add[0][0].coef/arr_down[0].coef;
    answer[n].power = add[0][0].power - arr_down[0].power;

    while(k>0)
    {
        z=-1;
        for(int i = 0, j = 0; i<=n_d, j<=n_u; i++, j++)
        {
            mult_result[i].coef = answer[n].coef * arr_down[i].coef;
            mult_result[i].power = answer[n].power + arr_down[i].power;
            if(add[n][j].coef - mult_result[j].coef == 0)continue;

            z++;
            add[n+1][z].coef = add[n][j].coef - mult_result[j].coef;
            add[n+1][z].power = add[n][j].power;

        }

        for (int i = 0; i < 7; i++)
        {

            if(add[n+1][i].power < arr_down[0].power||add[n+1][i].coef == 0)
            {
                k=-1;
                break;
            }

            if(add[n+1][i].power >= arr_down[0].power)
            {
                n++;
                answer[n].power = add[n][i].power - arr_down[0].power;
                answer[n].coef = add[n][i].coef/arr_down[0].coef;
                break;
            }
        }
    }
    printf("Answer is:\n");
    for(int i =0; i<sizeof(answer)/sizeof(answer[0]); i++)
    {
        if(answer[i].coef == 0)break;
        else if(answer[i].power == 0) printf("%.2f ",answer[i].coef);
        else if(answer[i].power == 1)printf("%.2f X + ",answer[i].coef);
        else printf("%.2f X^%d + ",answer[i].coef, answer[i].power);

    }
    printf("\nThe remainder is:\n");
    for(int i = 0; i<5; i++)
    {
        if(add[n+1][i].coef == 0)
        {
            printf("0");
            break;
        }
        else if(add[n+1][i].power == 0) printf("%.2f",add[n+1][i].coef);
        else if(add[n+1][i].power == 1) printf("%.2f X +",add[n+1][i].coef);
        else printf("%.2f X^%d + ",add[n+1][i].coef, add[n+1][i].power);
    }
    printf("  Divided by ");
    for(int i = 0; i<=n_d; i++)
    {
        if(arr_down[i].power == 0) printf("%.2f ",arr_down[i].coef);
        else if(arr_down[i].power == 1)printf("%.2f X + ",arr_down[i].coef);
        else printf("%.2f X ^%d +", arr_down[i].coef,arr_down[i].power);
    }
}

void main()
{
    int n_up = 0,n_down= 0;
    //an array containing the terms of the numerator
    struct Sx x_up[8]={0};
    //an array containing the terms of the denominator
    struct Sx x_down[8]={0};

    printf("Enter the greatest power in the numerator (max is 7):");
    scanf("%d" ,&n_up);

    printf("Enter the greatest power in the denominator (max is 7):");
    scanf("%d" ,&n_down);

    //initializing the power of each term
    for(int m = n_up , j = n_down; m>=0||j>=0 ; m--, j--)
    {
        x_up[n_up - m].power = m;
        x_down[n_down - j].power = j;
    }
    // taking the coeffecients of the numerator
    for(int i = 0; i<=n_up; i++)
    {
        printf("Enter the coef of x^%d in the numerator:",x_up[i].power);
        scanf("%f", &x_up[i].coef);
    }
    //taking the coeffecients of the denominator
    for(int i = 0; i<=n_down; i++)
    {
        printf("Enter the coef of x^%d in the denominator:",x_down[i].power);
        scanf("%f", &x_down[i].coef);
    }
    divide(x_up,x_down,n_down,n_up);
}

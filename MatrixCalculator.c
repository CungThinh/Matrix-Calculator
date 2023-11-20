#include<stdio.h>
#include<math.h>
//prototype
void Add(int matrix_A[10][10],int matrix_B[10][10],int row,int col);
void printMatrix(int matrix[10][10],int row, int col);
void matrixA_Input(int matrix_A[10][10],int rowA,int colA);
void matrixB_Input(int matrix_B[10][10],int rowB,int colB);
void Subtract(int matrix_A[10][10],int matrix_B[10][10],int row,int col);
void matrixMultiply(int matrix_A[10][10],int matrix_B[10][10],int rowA, int colA,int rowB,int colB);
void matrixScalarMultiply(int matrix[10][10],int row,int col,int lamda);

int main()
{
    int matrix_A[10][10];
    int matrix_B[10][10];
    int rowA;
    int rowB;
    int colA;
    int colB;
    int choice;  
    int matrixA_check = 0;
    int matrixB_check = 0; 
    int quit  = 0;
    while(quit ==0)
    {
        printf("\nOperation Menu\n");
        printf("\t1. Input matrix A:\n");  
        printf("\t2. Input matrix B:\n");  
        printf("\t3. to Add\n");  
        printf("\t4. to Subtract\n");  
        printf("\t5. to Scalar Multiply\n");  
        printf("\t6. to Multiply two matrices\n");  
        printf("\t7. QUIT\n");
        printf("Enter your choice: ");  
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                printf("Enter rows of matrix A:");
                scanf("%d",&rowA);
                printf("Enter colums of matrix A: ");
                scanf("%d",&colA);
                matrixA_Input(matrix_A,rowA,colA);
                matrixA_check = 1;
                break;
            case 2: 
                printf("Enter rows of matrix B:");
                scanf("%d",&rowB);
                printf("Enter colums of matrix B: ");
                scanf("%d",&colB);
                matrixB_Input(matrix_B,rowB,colB);
                matrixB_check = 1;
                break;
            case 3: 
                if(matrixA_check ==1 && matrixB_check ==1)
                {
                    if(rowA != rowB || colA != colB)
                    {
                        printf("Add two matrix should be the same size\n");
                        printf("Press 2 to reproduce matrix B");
                    }
                    else
                    {
                        printf("Sum of matrix A and B:\n");
                        Add(matrix_A,matrix_B,rowA,colA);
                    }
                }
                else
                {
                    printf("Empty matrix,Please add enough 2 matrix!");
                }
                break;
            case 4:
                if(matrixA_check ==1 && matrixB_check ==1)
                {
                    if(rowA != rowB || colA != colB)
                    {
                        printf("Subtract two matrix should be the same size\n");
                        printf("Press 2 to reproduce matrix B");
                    }
                    else
                    {
                        printf("Subtract of matrix A and B:\n");
                        Subtract(matrix_A,matrix_B,rowA,colA);
                    }
                }
                else
                {
                    printf("Empty matrix,Please add enough 2 matrix!");
                }
                break;
            case 5:
                printf("Which matrix you want to multiply");
                printf("A for 1 and B for 2\n");
                printf("Your choice: ");
                int deci;
                scanf("%d",&deci);
                
                    printf("A for 1 and B for 2\n");
                    printf("Which matrix you want to multiply:");
                    int deci; //decision
                    scanf("%d",&deci);
                    if(deci == 1)
                    {
                        printf("how much do you want to multiply: ");
                        int lamda;
                        scanf("%d",&lamda);
                        matrixScalarMultiply(matrix_A,rowA,colA,lamda);
                    }
                    else if(deci ==2 )
                    {
                        printf("how much do you want to multiply: ");
                        int lamda;
                        scanf("%d",&lamda);
                        matrixScalarMultiply(matrix_B,rowB,colB,lamda);
                    }
                    else
                        printf("An error occurred, please try again");
                }
                else
                {
                    printf("Empty matrix!Add matrix first");
                }
            case 6: 
                if(colA == rowB)
                {
                    matrixMultiply(matrix_A,matrix_B,rowA,colA,rowB,colB);
                }
                else
                    printf("Cannot multiply two matrix, please setting a new matrix!");
                break;
            case 7:
                quit = 1;
                break;
            default :
                break;
        }
    }
}
void matrixA_Input(int matrix_A[10][10],int rowA,int colA)
{
    //Element A:
    for(int i = 0 ; i < rowA; i ++)
    {
        for(int j = 0 ; j < colA  ; j++)
        {
            printf("Enter element [%d][%d] of matrix A:",i,j);
            scanf("%d",&matrix_A[i][j]);
        }
    }
}
void matrixB_Input(int matrix_B[10][10],int rowB,int colB)
{
    //Matrix B
    for(int i = 0 ; i < rowB; i ++)
    {
        for(int j = 0 ; j < colB  ; j++)
        {
            printf("Enter element [%d][%d] of matrix B:",i,j);
            scanf("%d",&matrix_B[i][j]);
        }
    }
}

void Add(int matrix_A[10][10],int matrix_B[10][10],int row,int col)
{
    int matrix_Sum[10][10];
    for(int i = 0 ; i < row; i ++)
    {
        for(int j = 0 ; j < col  ; j++)
        {
            matrix_Sum[i][j] = matrix_A[i][j] + matrix_B[i][j];
        }
    }
    printMatrix(matrix_Sum,row,col);
}

void Subtract(int matrix_A[10][10],int matrix_B[10][10],int row,int col)
{
    int matrix_Sum[10][10];
    for(int i = 0 ; i < row; i++)
    {
        for(int j = 0 ; j < col  ; j++)
        {
            matrix_Sum[i][j] = matrix_A[i][j] - matrix_B[i][j];
        }
    }
    printMatrix(matrix_Sum,row,col);
}

void printMatrix(int matrix[10][10],int row, int col)
{
    for(int i = 0 ; i < row; i ++)
    {
        for(int j = 0 ; j < col  ; j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixScalarMultiply(int matrix[10][10],int row,int col,int lamda)
{
    int result_matrix[10][10];
    for(int i = 0 ; i < row; i ++)
    {
        for(int j = 0 ; j < col  ; j++)
        {
            result_matrix[i][j] = lamda * matrix[i][j];
        }
    }
    printf("Matrix after multiply:\n");
    printMatrix(result_matrix,row,col);
}

void matrixMultiply(int matrix_A[10][10],int matrix_B[10][10],int rowA, int colA,int rowB,int colB)
{
    int result_matrix[10][10];
    for(int i = 0; i < rowA ; i++)
    {
        for(int j = 0 ; j < colB; j++)
        {
            int result = 0;
            for(int k = 0 ; k < colA ; k++)
                result = result + (matrix_A[i][k]*matrix_B[k][j]); // phần tử đứng trước là dòng, sau là cột
            result_matrix[i][j] = result;
        }
    }
    printf("Result after multiply 2 matrix\n");
    printMatrix(result_matrix,rowA,colB);
}
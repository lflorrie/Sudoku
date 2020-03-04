#include <iostream>
#include <ctime>
#include <random>
#include <cstdlib>
#include "includes/get_map.h"

using namespace std;

void    print_map(int** nums)
{
    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << nums[i][j] << " ";
            if (j == 2 || j == 5) { cout << "| "; }
        }
        cout << "\n";
        if (i == 2 || i == 5) { cout << "---------------------\n"; }
    }
}

int** create_map()   // ������� ������ ��������������� �������� ������
{
    int a;
    int **nums = new int*[9];
    for (int i = 0; i < 9; ++i)
        nums[i] = new int[9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == 0)
            {
                nums[i][j] = j + 1;
            }
            else
            {
                a = 3;
                if (i == 3 || i == 6) { a = 4; }
                if (a + nums[i - 1][j] < 10)
                {
                    nums[i][j] = (a + nums[i - 1][j]) % 10;
                }
                else
                {
                    nums[i][j] = (a + 1 + nums[i - 1][j]) % 10;
                }
            }
        }
    }
    return nums;
}
int** rows_mix(int** nums)
{
    int* c;
    srand(time(NULL));
    int a = rand() % 9;
    int b = a;
    while (a == b)
    {
        b = rand() % 3 + 3 * (a / 3);
    }
    c = nums[a]; 
    nums[a] = nums[b];
    nums[b] = c;
    return nums;
}
int** column_mix(int** nums)
{
    int c;
    srand(time(NULL));
    int a = rand() % 9;
    int b = a;
    while (a == b)
    {
        b = rand() % 3 + 3 * (a / 3);
    }
    for (int i = 0; i < 9; i++)
    {
        c = nums[i][a];
        nums[i][a] = nums[i][b];
        nums[i][b] = c;
    }
    return nums;
}
int** triple_rows(int** nums)
{
    int* c;
    srand(time(NULL));
    int a = rand() % 3;
    int b = a;
    while (a == b)
    {
        b = rand() % 3;
    }
    b = b * 3;
    for (int i = (a * 3); i < (3 + a * 3); i++)
    {
        c = nums[i];
        nums[i] = nums[b];
        nums[b] = c;
        b++;
    }    
    return nums;
}
int** triple_column(int** nums)
{
    int c;
    srand(time(NULL));
    int a = rand() % 3;
    int b = a;
    while (a == b)
    {
        b = rand() % 3;
    }
    b = b * 3;
    for (int j = (a * 3); j < (3 + a * 3); j++)
    {
        for (int i = 0; i < 9; i++)
        {
            c = nums[i][j];
            nums[i][j] = nums[i][b];
            nums[i][b] = c;
            
        }
        b++;
    }
    return nums;
}
int** transpose(int** nums)
{
    int c;
    for (int i = 1; i < 9; i++)
    {
        for (int j = 0; j < i; j++)
        {
            c = nums[i][j];
            nums[i][j] = nums[j][i];
            nums[j][i] = c;
        }
    }
    return nums;
}
int** initialize_map()
{
    default_random_engine generator;
    int** nums = create_map();   
    srand(time(NULL));
    int a = rand() % 20 + 80;
    
    for (int i = 0; i < a; i++)
    {
        
        uniform_int_distribution<int> dist(0, 4);
        int b = dist(generator);        
        switch (b)
        {
        case 0:           
            nums = rows_mix(nums);
            break;
        case 1:
            nums = column_mix(nums);
            break;
        case 2:
            nums = triple_rows(nums);
            break;
        case 3:
            nums = triple_column(nums);
            break;
        case 4:
            nums = transpose(nums);
            break;       
        }
    }
    return nums;
}
int** get_map(int c)
{
    int** nums = initialize_map();
    default_random_engine generator;
    uniform_int_distribution<int> dist(0, 8);    
    switch (c)
    {case 0:
        c = 28;
        break;
    case 1:
        c = 36;
        break;
    case 2:
        c = 81;
    }
    for (int k = 0, shell = 0; k != c && shell < 100; k++ , shell++)
    {
        int vars = 0;
        int rows_sum = 0;
        int column_sum = 0;
        int column = dist(generator);
        int rows = dist(generator);
        for (int i = 0; i < 9; i++)
        {
            if (nums[i][column] > 0)
                column_sum++;
        }
        for (int j = 0; j < 9; j++)
        {
            if (nums[rows][j] > 0)
                rows_sum++;
        }  
        for (int num = 1; num < 9; num++)
        {
            vars += is_right_place_i(nums, rows, column, num);
        }
        if (nums[rows][column] != 0 && vars == 1)
        {
            nums[rows][column] = 0;
            shell = 0;
        }
        else
        {
            k--;
        }
    }
    return nums;
}

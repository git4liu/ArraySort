
/************************************************************************/
/* 
给定一个包含1-n的数列，我们通过交换任意两个元素给数列重新排序。求最少需要多少次交换，能把数组排成按1-n递增的顺序，其中，数组长度不超过100。
例如：
原数组是3,2,1， 我们只需要交换1和3就行了，交换次数为1，所以输出1。
原数组是2,3,1，我们需要交换2和1，变成1,3,2，再交换3和2，变为1，2，3，总共需要的交换次数为2，所以输出2。

函数头部：

C/C++
int run(const int *a,int n);

java:
class solution {
        public static int run(int [] a)
} 

原文：http://hero.pongo.cn/Question/Details?ExamID=92&ID=94&bsh_bid=281776595

*/
/************************************************************************/

#include <iostream>

using namespace std;


// circle node type
struct circle_node
{
        int base;
        int point;
        bool deleted;
};


// find element from circle where base = base
int findElementByBase(const circle_node * circle , int size , int base)
{
        for(int i = 0 ; i < size ; ++ i)
        {
                if(circle[i].base == base)
                        return i;
        }
        return 0;
}



int run(const int *a,int n)
{
        int * arr = new int[n]();
        memcpy(arr , a , n * sizeof(int));


        // bubble sort
        for(int i = 0 ; i < n ; ++ i)
                for(int j = 0 ; j < n - i - 1 ; ++ j)
                        if(arr[j] > arr[j + 1])
                        {
                                int temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }


        //make circle
        circle_node *circle = new circle_node[n]();
        for(int i = 0 ; i < n ; ++i)
        {
                circle[i].base = a[i];
                circle[i].point = arr[i];
                circle[i].deleted = false;
        }


        //count circle number
        int circle_num = 0;
        int single_num = 0;
        for(int i = 0 ; i < n ; ++ i)
        {
                if(circle[i].base == circle[i].point)
                {
                        single_num ++ ;
                        continue;
                }
                if(circle[i].deleted)
                        continue;
                else
                {
                        circle[i].deleted = true;
                        int base = circle[i].base;
                        int point = circle[i].point;
                        int index = findElementByBase(circle , n , point);
                        while(circle[index].point != base)
                        {
                                circle[index].deleted = true;
                                index = findElementByBase(circle , n , circle[index].point);
                        }
                        circle[index].deleted = true;
                        ++ circle_num;
                }
        }

        //cout swap times
        int swap_times = circle_num == 0 ? 0 : n - circle_num - single_num;
        printf("swap_times : %d \n" , swap_times);

        delete [] circle;
        delete [] arr;
        return swap_times;
}

int main()
{

        const int arr[] = {
                93,52,12,70,25,36,18,37,27,99,68,40,84,
                3,76,57,60,19,33,41,92,87,58,13,15,43,
                28,63,64,59,31,97,14,69,4,88,72,65,10,
                23,67,81,21,80,90,82,74,1,95,42,89,29,
                53,44,17,61,50,8,85,73,30,62,7,46,54,
                77,9,34,38,16,26,56,71,32,83,48,49,11,
                91,35,24,75,78,20,86,45,94,55,98,2,39,
                96,5,22,100,6,79,66,51,47
        };


        run(arr , sizeof(arr) / sizeof(int));

        system("PAUSE");
        return 0;
}

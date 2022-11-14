#include <stdio.h>
void display(int *rarray, int l)
{
    if(l >= 3)
        printf("Third repeating element is: %d",rarray[2]);
    else if(l == 0)
        printf("There is no repeating element in the array");
    else 
        printf("Array has only %d repeating element",l);
}

void find(int *arr, int n){
    int i, j, count;
    int l = 0, x = 0;
    int found;
    int rarray[n]; 

    for (i = 0; i < n; i++)
    {
        count = 1;
        found = 1;
        int num = arr[i];
        for (x = 0; x < l; x++)
        {
            if (num == rarray[x])
            {
                found = 0;
                break;
            }
        }
        if (found)
        {
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] == num)
                    count++;
                if (count > 1)
                    break;
            }
            if (count > 1)
            {
                rarray[l] = num; 
                l++;
            }
        }
    }
     
     display(rarray, l);
}


int main()
{
    printf("JOHN ALEXANDER E 20011896\n");
    int n, i;
    printf("Enter Size: ");
    scanf("%d", &n);
    printf("Enter the Inputs\n");
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    find(arr,n);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main()
{
        void *ptr = NULL;

        ptr = (void*)malloc(4 * sizeof(void));

        int a = 10;

        ptr = &a;

        printf("\nptr = %p, a = %d\n",ptr,*(int*)ptr);

        return 0;
}

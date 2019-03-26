int        find_pivot(int *arr, int n)
{
        int i;
        int suml[n];
        int sumr[n];

        suml[0] = arr[0];
        i = 0;
        while (++i < n)
                suml[i] = suml[i - 1] + arr[i];
        sumr[--i] = arr[n - 1];
        if (sumr[i] == suml[i])
                return (i);
        while (--i >= 0)
        {
                sumr[i] = sumr[i + 1] + arr[i];
                if (sumr[i] == suml[i])
                        return (i);
        }
        return (-1);
}


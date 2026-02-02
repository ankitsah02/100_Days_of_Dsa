#include <stdio.h>

int maxProfit(int prices[], int n)
{
    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++)
    {
        if(prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        else
        {
            int profit = prices[i] - minPrice;
            if(profit > maxProfit)
                maxProfit = profit;
        }
    }

    return maxProfit;
}

int main()
{
    int n;
    scanf("%d", &n);

    int prices[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &prices[i]);

    printf("%d", maxProfit(prices, n));

    return 0;
}

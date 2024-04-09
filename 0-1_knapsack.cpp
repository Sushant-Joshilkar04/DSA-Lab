#include <iostream>
using namespace std;

void zero_one_knapsack(int profit[], int weight[], int n, int capacity) {
    int zero_one_matrix[n + 1][capacity + 1];
    for (int i = 0; i < capacity + 1; i++) {
        zero_one_matrix[0][i] = 0;
    }
    for (int i = 0; i < n + 1; i++) {
        zero_one_matrix[i][0] = 0;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < capacity + 1; j++) {
            if (weight[i - 1] <= j) {
                if (profit[i - 1] + zero_one_matrix[i - 1][j - weight[i - 1]] > zero_one_matrix[i - 1][j]) {
                    zero_one_matrix[i][j] = profit[i - 1] + zero_one_matrix[i - 1][j - weight[i - 1]];
                } else {
                    zero_one_matrix[i][j] = zero_one_matrix[i - 1][j];
                }
            } else {
                zero_one_matrix[i][j] = zero_one_matrix[i - 1][j];
            }
        }
    }
   
    cout<<endl<<"zero_one_matrix:"<<endl;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < capacity + 1; j++) {
            cout << zero_one_matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout<<"Maximum profit is: "<<zero_one_matrix[n][capacity]<<endl;
   

   
   
    int it=n,k=capacity;
    while(it>=0 && k>=0 && k>=weight[it-1])
    {
        if(zero_one_matrix[it-1][k]!= zero_one_matrix[it][k]  )
        {
            cout << profit[it-1] << " " << weight[it-1] << endl;
        it--;
        k=k-weight[it];
        }
        else
        {
            it--;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of Profit and weight: ";
    cin >> n;
    int profit[n];
    int weight[n];
    cout << "Enter profit and weight:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> profit[i] >> weight[i];
    }
    int capacity;
    cout << "Enter capacity: ";
    cin >> capacity;

    zero_one_knapsack(profit, weight, n, capacity);

    return 0;
}

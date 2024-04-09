//1 . Knapsack
#include<bits/stdc++.h>
using namespace std;

vector<float>wt,p,pbywt;

void sortByProfit(int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (p[j] < p[j + 1]) {
                swap(p[j], p[j + 1]);
                swap(wt[j], wt[j + 1]);
                swapped = true;
            }
        }
        
        if (swapped == false)
            break;
    }
}

float ByProfit(int n,int cap){
    
    sortByProfit(n);
    
    int weight=0;
    int i=0;
    float profit=0,x;
    while(weight<cap){
        if(wt[i]+weight<=cap) {
            weight = weight + wt[i];
            profit+=p[i];
        }
        else {
            x = (cap-weight)/wt[i];
            weight = cap;
            profit += p[i]*x;
        }
        i++;
    }
    return profit;
}

// By Weight 

void sortByWeight(int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (wt[j] > wt[j + 1]) {
                swap(p[j], p[j + 1]);
                swap(wt[j], wt[j + 1]);
                swapped = true;
            }
        }
        
        if (swapped == false)
            break;
    }
}

float ByWeight(int n,int cap){
    
    sortByWeight(n);
    
    int weight=0;
    int i=0;
    float profit=0,x;
    while(weight<cap){
        if(wt[i]+weight<=cap) {
            weight = weight + wt[i];
            profit+=p[i];
        }
        else {
            x = (cap-weight)/wt[i];
            weight = cap;
            profit += p[i]*x;
        }
        i++;
    }
    return profit;
}

//By Profit by weight ratio

void sortByProfitByWeight(int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (pbywt[j] < pbywt[j + 1]) {
                swap(pbywt[j] , pbywt[j +1 ]);
                swap(p[j], p[j + 1]);
                swap(wt[j], wt[j + 1]);
                swapped = true;
            }
        }
        
        if (swapped == false)
            break;
    }
}

float profitByWeight(int n,int cap){
    
    sortByProfitByWeight(n);
    
    int weight=0;
    int i=0;
    float profit=0,x;
    while(weight<cap){
        if(wt[i]+weight<=cap) {
            weight = weight + wt[i];
            profit+=p[i];
        }
        else {
            x = (cap-weight)/wt[i];
            weight = cap;
            profit += p[i]*x;
        }
        i++;
    }
    return profit;
}

int main() {
    int n,c;
    float t1,t2,t3;
    cout<<"Enter number of products : ";
    cin>>n;
    cout<<"Enter weight capacity : ";
    cin>>c;
    for(int i=0;i<n;i++) {
    
        cout<<"Enter wight of product "<<i+1<<" :";
        cin>>t1;
        wt.push_back(t1);
        
        cout<<"Enter profit of product "<<i+1<<" :";
        cin>>t2;
        p.push_back(t2);
        
        t3 = t2/t1;
        pbywt.push_back(t3);
        
    }
    float ans1,ans2,ans3;
    ans1 = profitByWeight(n,c);
    cout<<"Profit by using profit by Weight based method = "<<ans1<<endl;
    
    ans2 = ByProfit(n,c);
    cout<<"Profit by using profit based method = "<<ans2<<endl;
    
    ans3 = ByWeight(n,c);
    cout<<"Profit by using Weight based method = "<<ans3<<endl;
    
    if(ans1>=ans2 && ans1>=ans3){
        cout<<"Profit by using profit by Weight based method is optimal , which is = "<<ans1<<endl;
    }
    else if(ans2>=ans1 && ans2>=ans3) {
        cout<<"Profit by using profit based method is optimal , which is = "<<ans2<<endl;
    }
    else {
        cout<<"Profit by using Weight based method is optimal , which is = "<<ans3<<endl;
    }
    
}

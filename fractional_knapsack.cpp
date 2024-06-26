#include <bits/stdc++.h>


using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

double knapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < items.size(); i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items;
    int num;
    cout<<"Enter number of items: ";
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int w,v;
        cout<<"Enter weight and value of item-"<<i+1<<":";
        cin>>w>>v;
        Item item;
        item.weight=w;
        item.value=v;
        items.push_back(item);
    }
    int capacity;
    cout<<"enter maximum capacity: ";
    cin>>capacity;

    double maxValue = knapsack(capacity, items);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}

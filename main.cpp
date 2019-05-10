#include "experiment4.h"

int keys(int bucket)
{
    return random() % (3 * bucket);
}

int main() {
    double factor = 0.0;
    int key = 0;
    int bucket = 100;


    experiment1 Ex1Mod(bucket);
    cout << "Open Address Key Mod Experiment 1"  << endl;
    cout << "KEY   BUCKET  LOAD FACTOR     COLLISIONS" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < bucket; i++) {
        key = keys(bucket);
        cout << key << "      ";
        Ex1Mod.addkeymod(key);
        factor++;
        cout << "      " << factor / bucket << "          " <<Ex1Mod.collisions << endl;
    }
    cout << "\n";


    cout << "Open Address Key mid square Experiment 2"  << endl;
    cout << "KEY   BUCKET  LOAD FACTOR     COLLISIONS" << endl;
    cout << "----------------------------------------" << endl;
    experiment2 Ex2midsq(bucket);
    factor = 0.0;
    for (int i = 0; i < bucket; i++) {
        key = keys(bucket);
        cout << key << "      ";
        Ex2midsq.addkeymid(key);
        factor++;
        cout << "      " << factor / bucket << "          " <<Ex2midsq.collisions << endl;
    }
    cout << "\n";

    cout << "Seperate chaining Key mod Experiment 3"  << endl;
    cout << "KEY   BUCKET  LOAD FACTOR     COLLISIONS" << endl;
    cout << "----------------------------------------" << endl;
    experiment3 Ex3mod(bucket);
    factor=0.0;
    for(int i = 0; i < bucket; i++)
    {
        key = keys(bucket);
        cout << key << "      ";
        Ex3mod.addkeymod(key);
        factor++;
        cout << "      " << factor / bucket << "          " <<Ex3mod.collisions << endl;
    }
    cout << "\n";

    cout << "Seperate chaining Key mid square Experiment 4"  << endl;
    cout << "KEY   BUCKET  LOAD FACTOR     COLLISIONS" << endl;
    cout << "----------------------------------------" << endl;
    experiment4 Ex4midsq(bucket);
    factor=0.0;
    for(int i = 0; i < bucket; i++)
    {
        key = keys(bucket);
        cout << key << "      ";
        Ex4midsq.addkeymid(key);
        factor++;
        cout << "      " << factor / bucket << "          " <<Ex4midsq.collisions << endl;
    }

    return 0;
}
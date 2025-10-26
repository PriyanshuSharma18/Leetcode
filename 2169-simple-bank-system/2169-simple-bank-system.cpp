// this version uses a global C-array POOL
long long POOL[100000];
class Bank {
public:
    int n;
    long long* balance;
    Bank(vector<long long>& balance):n(balance.size()) {
        this->balance=POOL;
        copy(balance.begin(), balance.end(), this->balance);
    }

   bool transfer(int account1, int account2, long long money) {
        if (account1>n||account2>n||balance[account1-1]<money) 
            return 0;
        balance[account1-1]-=money;
        balance[account2-1]+=money;
        return 1;
    }

    bool deposit(int account, long long money) {
        if (account>n) return 0;
        balance[account-1]+=money;
        return 1;
    }

    bool withdraw(int account, long long money) {
        if (account>n||balance[account-1]<money) 
            return 0;
        balance[account-1]-=money;
        return 1;
    }
};
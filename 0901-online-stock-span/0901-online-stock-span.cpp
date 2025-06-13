class StockSpanner {
public:
    vector<int> stock;

    StockSpanner() {
        stock = vector<int>();
    }

    int next(int price) {
        stock.push_back(price);
        for (int i = stock.size() - 2; i >= 0; i--) {
            if (stock[i] > price) {
                return stock.size() - 1 - i;
            }
        }
        return stock.size();
    }
};
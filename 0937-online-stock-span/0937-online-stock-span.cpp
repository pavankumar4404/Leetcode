class StockSpanner {
public:
    stack<pair<int, int>> st;
    int i;
    StockSpanner() {
        i = -1;
        st.push({INT_MAX, -1});
    }
    
    int next(int price) {
        i++;
        while(st.top().first <= price){
            st.pop();
        }
        int ans = i - st.top().second;
        st.push({price, i});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
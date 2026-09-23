class Solution {
    void update_with_add(stack<int>& st) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(a + b);
    }
    void update_with_mult(stack<int>& st) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(a*b);
    }
    void update_with_subtract(stack<int>& st) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(b-a);
    }

    void update_with_div(stack<int>& st) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        st.push(b/a);
    }

   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> store;
        for (auto it : tokens) {
            if (!(it == "+" || it == "-" || it == "*" || it == "/")) {
                store.push(stoi(it));
            } else {
                if (it == "+") {
                    update_with_add(store);
                }
                if (it == "-") {
                    update_with_subtract(store);
                }
                if (it == "*") {
                    update_with_mult(store);
                }
                if (it == "/") {
                    update_with_div(store);
                }
            }
        }
        return store.top();
    }
};

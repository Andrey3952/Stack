#include <iostream>
#include "stack.h"

int main()
{
    Stack st;

    st.push(2);
    st.push(7);
    st.push(40);
    st.show();
    st.pop();
    st.show();
    st.push(4);
    st.push(4);
    st.show();
    st.multiPop(3);
    st.show();
    // st2 = st;
    Stack st2(st);
    st2 = st;
    st2.show();
}

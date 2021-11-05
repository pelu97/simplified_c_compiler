int a;

int x(float z) { return z*a-a-z+a; }

float cca(int list l) {
    if (l == NIL) return 0;
    read(a);
    writeln(a);
    return
        ?%%(x >> x << x(1) : x(2) : 32 : NIL)
        * ?(1.1 + 1.1/2 - 3.3 : x(?l) : 2.2 : NIL)
        + ?(x >> %%(9.8: l))
        / cca(1.0 - -2 : a + a : NIL)
        - ?%%l;
}

int main() {
    a = 5;
    int a;
    read(a);
    a = cca(a : a : a : a : NIL);
    if (a > 10) writeln(">10");
    else writeln(a);
    return a * 0.5;
}

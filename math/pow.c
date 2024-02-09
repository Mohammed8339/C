
double static power(double x, int y) {
    double result = (x * x);
    y = y - 1;
    if (y == 1) {
        return result;
    }
    else {
        power(result, y);
    }
}
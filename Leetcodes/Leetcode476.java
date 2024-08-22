class Solution {
    public int findComplement(int num) {
        String binary = decimalToBinary(num);
        int n = binary.length();

        StringBuilder complement = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (binary.charAt(i) == '0') {
                complement.append('1');
            } else {
                complement.append('0');
            }
        }

        return binaryToDecimal(complement.toString());
    }

    private String decimalToBinary(int n) {
        if (n == 0) return "0";
        StringBuilder binary = new StringBuilder();
        while (n > 0) {
            binary.insert(0, n % 2);
            n = n / 2;
        }
        return binary.toString();
    }

    private int binaryToDecimal(String binaryStr) {
        int decimal = 0;
        int n = binaryStr.length();
        for (int i = 0; i < n; i++) {
            if (binaryStr.charAt(n - i - 1) == '1') {
                decimal += Math.pow(2, i);
            }
        }
        return decimal;
    }
}
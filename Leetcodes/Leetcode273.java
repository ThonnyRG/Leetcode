class Solution {
    public String numberToWords(int num) {
        String[] to19 = "One,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Eleven,Twelve,Thirteen,Fourteen,Fifteen,Sixteen,Seventeen,Eighteen,Nineteen".split(",");
        String[] tens = "Twenty,Thirty,Forty,Fifty,Sixty,Seventy,Eighty,Ninety".split(",");

        String words(int n) {
            if (n < 20) return to19[n - 1];
            if (n < 100) return tens[n / 10 - 2] + (n % 10 > 0 ? " " + words(n % 10) : "");
            if (n < 1000) return words(n / 100) + " Hundred" + (n % 100 > 0 ? " " + words(n % 100) : "");
            String[] units = {"", "Thousand", "Million", "Billion"};
            int i = 0;
            while (n >= 1000) {
                if (n % 1000 != 0) {
                    return words(n / 1000) + " " + units[i] + (n % 1000 > 0 ? " " + words(n % 1000) : "");
                }
                n /= 1000;
                i++;
            }
            return words(n) + " " + units[i];
        }

        return num == 0 ? "Zero" : words(num);
    }
}
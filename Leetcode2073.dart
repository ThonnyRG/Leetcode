class Solution {
  int timeRequiredToBuy(List<int> tickets, int k) {
    int total = 0;

    for (int i = 0; i < tickets.length; i++) {
      if (i <= k) {
        total += tickets[i].compareTo(tickets[k]) <= 0
            ? tickets[i]
            : tickets[k];
      } else {
        total += tickets[i].compareTo(tickets[k] - 1) <= 0
            ? tickets[i]
            : tickets[k] - 1;
      }
    }

    return total;
  }
}

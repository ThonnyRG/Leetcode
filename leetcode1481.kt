class Solution {
    data class Pair(val key: Int, val freq: Int)

    fun findLeastNumOfUniqueInts(arr: IntArray, k: Int): Int {
        val map = HashMap<Int, Int>()
        arr.forEach { a -> map[a] = map.getOrDefault(a, 0) + 1 }

        val list = ArrayList<Pair>()
        for ((key, value) in map) {
            list.add(Pair(key, value))
        }
        list.sortByDescending { it.freq }

        var remainingK = k
        while (remainingK > 0) {
            val freq = list.last().freq
            if (freq <= remainingK) {
                list.removeAt(list.size - 1)
                remainingK -= freq
            } else {
                break
            }
        }
        return list.size
    }
}
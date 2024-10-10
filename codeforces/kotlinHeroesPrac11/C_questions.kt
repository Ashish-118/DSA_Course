import kotlin.math.abs

fun solve(v: List<Long>, n: Int): Long {
    var i = 0
    var j = n - 1


    while (i < n - 1 && v[i] == v[i + 1]) {
        i++
    }


    while (j > 0 && v[j] == v[j - 1]) {
        j--
    }


    if (j == 0) {
        return 0L
    }

 
    if (v[0] == v[n - 1]) {
        return abs((i + 1) - (j - 1)).toLong() + 1
    } else {
        return if ((i + 1) == (n - j)) {
            (n - (i + 1)).toLong()
        } else {
            (n - maxOf((i + 1), (n - j))).toLong()
        }
    }
}

fun main() {
    val t = readLine()!!.toInt() 
    repeat(t) {
        val n = readLine()!!.toInt() 
        val v = readLine()!!.split(" ").map { it.toLong() } 
        println(solve(v, n)) 
    }
}

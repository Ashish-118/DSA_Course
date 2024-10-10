import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)
    val t = scanner.nextInt()  

    for (tc in 1..t) {
        val n = scanner.nextInt()  
        val s = scanner.next()     

        var i = 0
        var countOne = 0

        
        while (i < n && s[i] != '0') {
            countOne++
            i++
        }

       
        val countZero = s.count { it == '0' }

        val matrix = countOne - 1

        if (n == 3 && countOne == 3) {
            println("NO")
        } else if (n == 4 && countOne == 4) {
            println("YES")
        } else if ((matrix - 2) * (matrix - 2) == countZero) {
            println("YES")
        } else {
            println("NO")
        }
    }
}

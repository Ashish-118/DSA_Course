import java.util.Scanner
import kotlin.math.*

fun main() {
    val scanner = Scanner(System.`in`)

    val n = scanner.nextInt()  // Number of pairs to process

    for (i in 1..n) {
        val num1 = scanner.nextInt()
        val num2 = scanner.nextInt()

        // Print minimum and maximum in one line
        println("${min(num1, num2)} ${max(num1, num2)}")
    }
}

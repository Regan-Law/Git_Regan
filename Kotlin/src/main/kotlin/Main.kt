fun main(args: Array<String>) {
    println("Hello World!")
}
    // Try adding program arguments via Run/Debug configuration.
    // Learn more about running applications: https://www.jetbrains.com/help/idea/running-applications.html.
    println("Program arguments: ${args.joinToString()}")
companion object Info {
    fun <T> info(list: List<T>): String {
        return if (list.isEmpty()) {
            "[]"
        } else {
            list.joinToString(prefix = "[", postfix = "]")
        }
    }
}

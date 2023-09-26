// 定义汽车接口
interface Car {
    fun manufacture()
}

// 宝马汽车类
class BMWCar : Car {
    override fun manufacture() {
        println("宝马汽车")
    }
}

// 奔驰汽车类
class BenzCar : Car {
    override fun manufacture() {
        println("奔驰汽车")
    }
}

// 汽车工厂接口
interface CarFactory {
    fun createCar(): Car
}

// 宝马汽车工厂
class BMWFactory : CarFactory {
    override fun createCar(): Car {
        return BMWCar()
    }
}

// 奔驰汽车工厂
class BenzFactory : CarFactory {
    override fun createCar(): Car {
        return BenzCar()
    }
}

// 客户端代码
fun main() {
    val bmwFactory: CarFactory = BMWFactory()
    val bmwCar: Car = bmwFactory.createCar()
    bmwCar.manufacture()

    val benzFactory: CarFactory = BenzFactory()
    val benzCar: Car = benzFactory.createCar()
    benzCar.manufacture()
}
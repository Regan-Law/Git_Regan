plugins {
	kotlin("jvm") version "1.8.20"
	application
}

group = "org.ReganLaw"
version = "1.0-SNAPSHOT"

repositories {
	mavenCentral()
}

dependencies {
	testImplementation(kotlin("test"))
	implementation("com.oracle.database.jdbc:ojdbc8:19.3.0.0")
}

tasks.test {
	useJUnitPlatform()
}

kotlin {
	jvmToolchain(11)
}

application {
	mainClass.set("MainKt")
}
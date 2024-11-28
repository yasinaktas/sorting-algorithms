fun insertion_sort(array:MutableList<Int>, size:Int){
	for(i in 1 until size){
		for(j in i downTo 1){
			if(array[j] < array[j - 1]){
				var temp = array[j]
				array[j] = array[j - 1]
				array[j - 1] = temp
			}
		}
	}
}

fun main(){
	val size = 20
	val array = MutableList(size){it + 1}
	array.shuffle()
	println(array.joinToString())
	insertion_sort(array,size)
	println(array.joinToString())
}

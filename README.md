# Auto_ptr_weakPTR_iniquePTR_sharedPTR

std::shared_ptr (С++11)

Умный указатель с подсчетом ссылок. Что это значит. Это значит, что где-то есть некая переменная, которая хранит количество указателей, которые ссылаются на объект. Если эта переменная становится равной нулю, то объект уничтожается. Счетчик инкрементируется при каждом вызове либо оператора копирования либо оператора присваивания. Так же у shared_ptr есть оператор приведения к bool, что в итоге дает нам привычный синтаксис указателей, не заботясь об освобождении памяти.
 <div style="color:yellow;height:30px;font-size:35px;">说明</div>



- String 参考stl风格 包含了查找匹配字符串函数find().
- 在struct.h 中定义课程和课外活动的信息结构.
- B-Tree 构造B-Tree时目前可用键值有课程或课外活动名称Name，开始时间BeginTime，以以上枚举值为参数可构造一个对应键值的B-Tree.

  - B-Tree 可按键值高效查找并依据键值自动排序(中文以首字拼音首字母顺序排序)，其中对应每个键值存储一个itemlist(以便存放具有相同键值的item)，itemlist中存放item,存放前先以一个课程对象或课外活动对象的指针为参数构造一个item之后直接以该item为参数调用insertItem()插入B-Tree.
  - 移除数据项时先构造一个样例item，然后以该item为参数调用remove()，即可在B-Tree中查找到对应项并移除.
  - search()可以一个int类型或String类型作为关键字查找到对应的itemlist.
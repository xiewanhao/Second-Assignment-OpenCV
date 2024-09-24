# 使用C++和OpenCV进行图像处理
## 环境配置
### 环境配置过程中为出现任何问题
## 编写项目结构
### 通过*mkdir*编写项目结构
[![pAMe98x.jpg](https://s21.ax1x.com/2024/09/21/pAMe98x.jpg)](https://imgse.com/i/pAMe98x)
### 在 `OpenCV_Project` 中使用命令下载测试图片至`resources`
[![pAMePxK.png](https://s21.ax1x.com/2024/09/21/pAMePxK.png)](https://imgse.com/i/pAMePxK)
## 图像实现情况
### CMakeLists编写
#### 成功编写
[![pAMenPI.png](https://s21.ax1x.com/2024/09/21/pAMenPI.png)](https://imgse.com/i/pAMenPI)
### 主程序开发及图像处理结果
#### 图像颜色空间转化
##### 转化为灰度图，图像如下：
[![pAMeKRP.png](https://s21.ax1x.com/2024/09/21/pAMeKRP.png)](https://imgse.com/i/pAMeKRP)
##### 转化为HSV图，图像如下：
[![pAMeMxf.png](https://s21.ax1x.com/2024/09/21/pAMeMxf.png)](https://imgse.com/i/pAMeMxf)
#### 在程序开发中经常出现如下报错，但是却不影响终端运行
[![pAMelM8.png](https://s21.ax1x.com/2024/09/21/pAMelM8.png)](https://imgse.com/i/pAMelM8)
#### 应用各种滤波操作
##### 应用均值滤波，图像如下：
[![pAMe1sS.png](https://s21.ax1x.com/2024/09/21/pAMe1sS.png)](https://imgse.com/i/pAMe1sS)
##### 应用高斯滤波，图像如下：
![F1BBA75267E06F0C77D2C8208EBF9C55](https://img.picgo.net/2024/09/21/F1BBA75267E06F0C77D2C8208EBF9C5505487c9a2157be4c.png)
#### 特征提取
##### 掩模图像：
![A6A5B5F5AA9BBDA45CA91FF59707F385](https://img.picgo.net/2024/09/21/A6A5B5F5AA9BBDA45CA91FF59707F385073f703a9ab3166d.png)
##### 寻找图像的外轮廓：
![573B19C68DABA71EAD15BABB7F01A300](https://img.picgo.net/2024/09/21/573B19C68DABA71EAD15BABB7F01A300ebd01e5dfb3d762c.png)
##### 寻找并绘制图像的bounding boxes
![5FCAF702943503730E61BA37A4332F72](https://img.picgo.net/2024/09/21/5FCAF702943503730E61BA37A4332F729bc87b5fba1285e4.png)
##### 提取高亮颜色区域进行图形学处理
###### 灰度化，图像如下：
![EAD7EB74077245668658FD7A6A5B1564](https://img.picgo.net/2024/09/21/EAD7EB74077245668658FD7A6A5B1564b07b40ca9cf346d0.png)
###### 二值化，图像如下：
![8A4AF4123F5CC5A16AC54595D301413E](https://img.picgo.net/2024/09/21/8A4AF4123F5CC5A16AC54595D301413E217bf1150d999b55.png)
###### 膨胀，图像如下：
![27EB55CC5A6B536880D74113E02050DC](https://img.picgo.net/2024/09/21/27EB55CC5A6B536880D74113E02050DC7bf6a385225313bf.png)
###### 腐蚀，图像如下：
![27EB55CC5A6B536880D74113E02050DC](https://img.picgo.net/2024/09/21/27EB55CC5A6B536880D74113E02050DC7bf6a385225313bf.png)
###### 对处理后的图像进行漫水处理，显示如下：
![7C12569EE753AB5904F8B8AA3909B908](https://img.picgo.net/2024/09/21/7C12569EE753AB5904F8B8AA3909B908bb9c7e437633535a.png)
#### 图像绘制
##### 绘制任意圆形，方形，文字：
![30847BA872404839496D34CB161D0A44](https://img.picgo.net/2024/09/22/30847BA872404839496D34CB161D0A443708ed0d2caedbb1.png)
![4D74D5049354CF004E3E63ADE2C2CF74](https://img.picgo.net/2024/09/22/4D74D5049354CF004E3E63ADE2C2CF7403be29faf2c7648d.png)
##### 绘制红色的bounding box,显示如下：
[![pAMyTvq.png](https://s21.ax1x.com/2024/09/22/pAMyTvq.png)](https://imgse.com/i/pAMyTvq)
#### 对图像进行处理
##### 将图像旋转35度，图像如下：
[![pAMyj54.png](https://s21.ax1x.com/2024/09/22/pAMyj54.png)](https://imgse.com/i/pAMyj54)
##### 将图像裁剪为原图的左上角1/4,图像如下：
[![pAMyzG9.md.png](https://s21.ax1x.com/2024/09/22/pAMyzG9.md.png)](https://imgse.com/i/pAMyzG9)

---

# 完成思路
## 1.主要由于时间较为紧张，先通过询问chatGPT，得到代码并进行调试得到图像。，再在调试代码中有问题的部分上网进行查询并解惑，最后再开始系统的学习opencv。在使用chatGPT中最终要的就是用简单直白，易于chatGPT理解的语言去解释自己的问题。
## 2.现在通过B站的视频进行自主学习，查漏补缺 [B站最好的OpenCV课程推荐](https://www.bilibili.com/video/BV1PV411774y/?spm_id_from=333.337.search-card.all.click)。

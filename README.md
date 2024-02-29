# Morphological Image Processing

- **數學型態學影像處理應用 Morphological Image Processing**
- 利用數學型態學影像處理運算(erode(), dilate()等函式)，計算出所附圖像中圍棋個數。

## :small_blue_diamond: Environment:
- Windows 10, Visual Studio 2019, OpenCV 4.5.0, C++

## :small_blue_diamond: Method:
* 輸入圖片路徑和檔名，讀取圖片，輸出原圖(Original)。
* 將圖片以灰階形式讀取。
* erode()，侵蝕讓圖片細化影像；dilate()，膨脹讓圖片的輪廓恢復正常，輸出侵蝕和膨脹過後的灰度圖(Erosion and Dilation)。
![](https://github.com/jaifenny/Morphological_Image_Processing/blob/main/picture/01.png)
* HoughCircles(image, method, dp, minDist, circles, param1, param2, minRadius, maxRadius)，偵測圓形，image:侵蝕和膨脹過後的灰度圖，method；HOUGH_GRADIENT，爲檢測方法，dp:檢測內側圓心的分辨率，minDist:表示兩個圓之間的最短距離，param1:method設置的檢測方法的對應的參數，canny邊緣檢測算子的高閾值，param2: method設置的檢測方法的對應的參數，檢測階段圓心的累加器閾值，minRadius:半徑的最小值，maxRadius:半徑的最大值。
* Circle(image, center, radius, color, thickness, line type, shift)函式畫圓，image:圖像, center:圓心座標, radius:圓的半徑, color:線條顏色, thickness:線條寬度, line type:線條類型, shift: 圓心和半徑值的小數點位數，輸出畫圓形後的圖像(Result)。
* 輸出棋子數量。

## :small_blue_diamond: Result:
- IMG_5702.JPG:實際棋子數量=24，計算結果=23
- IMG_5703.JPG:實際棋子數量=31，計算結果=31
- IMG_5704.JPG:實際棋子數量=31，計算結果=31

![](https://github.com/jaifenny/Morphological_Image_Processing/blob/main/picture/r1.png)

![](https://github.com/jaifenny/Morphological_Image_Processing/blob/main/picture/r2.png)

![](https://github.com/jaifenny/Morphological_Image_Processing/blob/main/picture/r3.png)

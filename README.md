# state space model
状态空间描述为：

$$\dot{x}=Ax(t)+Bu(t)\quad\quad\quad\quad\quad(1)$$
$$y=Cx(t)+Du(t)\quad\quad\quad\quad\quad(2)$$
其中，
$$\dot{x}=\frac{x_{k+1}-x_{k}}{h}\quad\quad\quad\quad\quad\quad\quad(3)$$
则有
$$\frac{x_{k+1}-x_{k}}{h}=Ax_k+Bu_k$$
$$x_k=x(k*h),x_{k+1}=x((k+1)*h)\quad\quad(4)$$
(5)可能导致不确定性，参考backward Euler method。所以,我们使用下面的方程：
$$\dot{x}=\frac{x_{k}-x_{k-1}}{h}$$
则：
$$\frac{x_{k}-x_{k-1}}{h}=Ax_k+Bu_k$$
$$x_k-x_{k-1}=hAx_k+hBu_k$$
$$x_k-hAx_k=x_{k-1}+hBu_k$$
$$(I-hA)x_k=x_{k-1}+hBu_k$$
$$x_k=(I-hA)^{-1}x_{k-1}+(I-hA)^{-1}hBu_k$$
由于step $h$ 极小，则上式可以看作：
$$x_k=(I-hA)^{-1}x_{k-1}+(I-hA)^{-1}hBu_{k-1}\quad\quad(5)$$
而输出值:
$$y_k=Cx_k+Du_k\quad\quad(6)$$



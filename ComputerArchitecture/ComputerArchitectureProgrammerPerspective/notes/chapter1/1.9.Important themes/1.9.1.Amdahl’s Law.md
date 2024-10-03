---
tags:
  - "#study"
cssclasses:
  - center-images
---
> When we speed up one part of a system, how significant this part is and how much it sped up **impacts** the overall system performance.

Supposed the time to execute some app is $T_{old}$, some part of the system requires a fraction $\alpha$ of this time, and we improve that part’s performance by a factor of $k$. The part **originally** requires $\alpha T_{old}$ and now it requires $\frac{\alpha T_{old}}{k}$

=> The time increased is $\frac{\alpha}{k} - \alpha$

$$
T_{new} = (1-\alpha)T_{old} + \frac{\alpha T_{old}}{k} = T_{old}\left[ (1-\alpha) + \frac{\alpha}{k} \right]
$$

The speedup:

$$
S = \frac{1}{(1-\alpha) + \frac{\alpha}{k}}
$$

[[Expressing relative performance]]

[[Practice Problems]]

[[Speed up until it takes a negligible amount of time]]

Some applications:
- For razor blade companies: Reduce the cost of manufacturing
- For students: Improve his/her grade point average
- For computer systems: Improve performance by factors of 2
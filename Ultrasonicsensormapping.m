clear all;
a = arduino
sensor = addon(a,'JRodrigoTech/HCSR04','D12','D13')
s = servo(a,'D3')
j=1
k=1
A = zeros(180,2);
for theta=0:1/180:1
    writePosition(s,theta);
    val1=readDistance(sensor)
    pause(0.2);
    val2=readDistance(sensor)
    val=(val1+val2)/2;
    A(j,1)=j-1;
    A(j,2)=val
    j=j+1;
end
for theta=1:-1/180:0
    writePosition(s,theta);
    val1=readDistance(sensor)
    pause(0.2);
    val2=readDistance(sensor)
    val=(val1+val2)/2;
    A(j-k,2)=(A(j-k,2)+val)/2;
    k=k+1;
end
polarplot(A(:,1)*pi/180,A(:,2));
thetalim([0 180]);

    %copyright :- PRANAV SHARMA
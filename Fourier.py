import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import *
##Almacenamiento de datos##
datos_1 = np.genfromtxt("signalSuma.dat")
datos_2 = np.genfromtxt("signal.dat")
#print len(data1[:,1])
N = 2048
dt = abs(datos_1[1,0]-datos_2[2,0])
##subplots con el grafico para cada senal##
plt.figure()
plt.subplot(2,1,1)
plt.title("signalSuma")
plt.xlabel("Tiempo(s)")
plt.ylabel("Amplitud")
plt.plot(datos_1[:,0],datos_1[:,1])

plt.subplot(2,1,2)
plt.title("signal")
plt.xlabel("Tiempo(s)")
plt.ylabel("Amplitud")
plt.plot(datos_2[:,0],datos_2[:,1])

plt.savefig("signal_subplots.pdf")


###fourier


def fourier (N, datos):
	fourie = []
	for n in range(N): 
		suma = 0
		for k in range(N): 
			suma+=((datos[k,1])*(np.exp((-1j * 2 * np.pi * k * (n/N)))))

		fourie.append(suma)
	return (fourie)

f_1= np.asarray(fourier(N, datos_1))
f_2= np.asarray(fourier(N, datos_2))


#print fftfreq(N,d=dt)
##graficos de la transformada de Fourier de ambas senales##
#print (len(res),len(res2),len(fftfreq(N,d=dt)))

plt.figure()
plt.plot(f_1)
#plt.plot(fftfreq(N,d=dt),res2)
plt.show()
##espectrograma de las senales##
plt.figure()
plt.subplot(2,1,1)
plt.specgram(datos_1[:,1])

plt.subplot(2,1,2)
plt.specgram(datos_2[:,1])
#plt.show()


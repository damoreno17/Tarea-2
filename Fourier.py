import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq
#datos
datos_sigsum = np.genfromtxt("signalSuma.dat")
datos_signal = np.genfromtxt("signal.dat")

signal= datos_signal[:,1]
t_signal= datos_signal[:,0]

t_sigsum= datos_sigsum[:,0]
sigsum= datos_sigsum[:,1]

#senalplot

plt.figure()
plt.subplot(1,2,1)
plt.title("Senal a partir de signal.dat")
plt.xlabel("Tiempo (s)")
plt.ylabel("Amplitud")
plt.plot(t_signal,signal)

plt.subplot(1,2,2)
plt.title("Senal partir de signalsum.dat")
plt.xlabel("Tiempo(s)")
plt.ylabel("Amplitud")
plt.plot(t_sigsum,sigsum)

plt.savefig("subplot_SignalySignalsum.pdf")

plt.close()


#trasformada

N=len(t_signal)
dt = abs(datos_sigsum[1,0]-datos_signal[2,0])


def fourier (N, datos):
	fourie = []
	for m in range(N): 
		suma = 0
		for n in range(N): 
			suma+=((datos[n,1])*(np.exp((-1j * 2 * np.pi * n * (1.0*m/N)))))

		fourie.append(suma)
	return (fourie)

f_1= abs(np.asarray(fourier(N, datos_signal)))
f_2= abs(np.asarray(fourier(N, datos_sigsum)))
frecuencia = fftfreq(N, d=dt)

#fourier con fft
fourfast = np.fft.fft(datos_signal)
print (fourfast)

#print fftfreq(N,datos=dt)

#graph fourier
#print (len(res),len(res2),len(fftfreq(N,d=dt)))

plt.figure()
plt.plot(frecuencia, f_1, label=("signal"))
plt.plot(frecuencia, f_2, label=("sigsum"))
plt.legend(loc ="best")
plt.title("fourier Signal")
plt.xlabel("Frecuencia")
plt.ylabel("densidad de Frec.")
plt.savefig("Fourier_signal.pdf")
plt.close()





#Temblor
temblor= np.genfromtxt("temblor.tex", skip_header=4)
N_2=len(temblor)

signaltemblor = temblor [:]

plt.figure()
plt.plot (signaltemblor)
plt.title("senal a partir de temblor.tex")
plt.xlabel("tiempo")
plt.ylabel("amplitud")
plt.savefig("Temblor.pdf")
plt.close()

#fourier temblor

frecuencia_t = fftfreq (N_2, d=0.01)
plt.figure()
plt.plot (frecuencia_t, abs(fft (temblor)))
plt.title ( "Fourier temblor" )
plt.xlabel("Freq (Hz)")
plt.ylabel("amplitud")
plt.savefig ("fourier_temblor.pdf")
plt.close()

#espectrogramas 

plt.figure()
plt.title("Espectrograma Signal")
plt.subplot(2,1,1)
plt.specgram(signal)
plt.xlabel("tiempo")
plt.ylabel("freq. (Hz)")
plt.title("Senal")

plt.title("Espectrograma SigSum")
plt.subplot(2,1,2)
plt.specgram(sigsum)
plt.xlabel("tiempo")
plt.ylabel("freq. (Hz)")
plt.title("Senales sumadas")
plt.savefig("espectrogramas_senales.pdf")
plt.close()

plt.figure()
plt.specgram(temblor)
plt.title("Espectrograma del temblor")
plt.xlabel("tiempo")
plt.ylabel("freq. (Hz)")
plt.savefig("espectro_temblor.pdf")
plt.close()

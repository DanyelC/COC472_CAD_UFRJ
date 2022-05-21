import pandas as pd
import numpy as np
import matplotlib as plt

plt.rcParams["figure.figsize"] = [7.50, 3.50]
plt.rcParams["figure.autolayout"] = True

headers = ['Name', 'Age', 'Marks']

fort = pd.read_csv('Fortran\\fort.csv')
c = pd.read_csv('C\\c.csv')

c.columns = ['N', 'GB', 't1', 't2']
fort.columns = ['N', 'GB', 't1', 't2']

font_t = {'family': 'serif',
        'color':  'black',
        'weight': 'normal',
        'size': 16,
        }

font_l = {'family': 'serif',
        'color':  'black',
        'weight': 'normal',
        'size': 13,
        }

font_l2 = {'family': 'serif',
        'color':  'black',
        'weight': 'normal',
        'size': 11,
        }

x = fort['N']
y = fort['t1']
z = fort['t2']
# plot
plt.plot(x,y)
plt.plot(x,z)
# beautify the x-labels
plt.gcf().autofmt_xdate()
plt.legend(["Método linha-coluna","Método coluna-linha"], shadow=True, prop={'family':'serif','weight':'roman','size':12})
plt.title('Tempo de execução em Fortran', fontdict=font_t)
plt.ylabel('tempo (s)', fontdict = font_l)
plt.xlabel('Dimensão dos arrays', fontdict = font_l)
#plt.subplots_adjust(left=0.15)
plt.show()


x = c['N']
y = c['t1']
z = c['t2']
# plot
plt.plot(x,y)
plt.plot(x,z)
# beautify the x-labels
plt.gcf().autofmt_xdate()
plt.legend(["Método linha-coluna","Método coluna-linha"], shadow=True, prop={'family':'serif','weight':'roman','size':12})
plt.title('Tempo de execução em C', fontdict=font_t)
plt.ylabel('tempo (s)', fontdict = font_l)
plt.xlabel('Dimensão dos arrays', fontdict = font_l)

plt.show()
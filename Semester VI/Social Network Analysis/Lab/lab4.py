import community as community_louvain
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import networkx as nx

import urllib.request
import io
import zipfile

# Loading Karate Club Graph
GG_Karate = nx.karate_club_graph ()

# Loading Football Club Graph
url = "http://www-personal.umich.edu/~mejn/netdata/football.zip"
sock = urllib.request.urlopen (url)
sockRead = io.BytesIO (sock.read ())
sock.close ()

zfFootball = zipfile.ZipFile (sockRead)
txtFootball = zfFootball.read ("football.txt").decode ()
gmlFootball = zfFootball.read ("football.gml").decode ()
gmlFootball = gmlFootball.split ("\n") [1:]

GG_Football = nx.parse_gml (gmlFootball)

# Loading Dolphin Network Graph
zfDolphin = zipfile.ZipFile ("dolphins.zip")
txtDolphin = zfDolphin.read ("dolphins.txt").decode ()
gmlDolphin = zfDolphin.read ("dolphins.gml").decode ()
gmlDolphin = gmlDolphin.split ("\n") [1:]

GG_Dolphin = nx.parse_gml (gmlDolphin)

#Computing the Best Partition
partitionKarate = community_louvain.best_partition (GG_Karate)
partitionFootball = community_louvain.best_partition (GG_Football)
partitionDolphin = community_louvain.best_partition (GG_Dolphin)

# Drawing the Graph
posKarate = nx.spring_layout (GG_Karate)
posFootball = nx.spring_layout (GG_Football)
posDolphin = nx.spring_layout (GG_Dolphin)

# Colouring the Nodes according to their Partitions
plt.figure (figsize = (15, 15))
plt.title ("KARATE CLUB NETWORK")
cmap = cm.get_cmap ('viridis', max (partitionKarate.values ()) + 1)
nx.draw_networkx_nodes (GG_Karate, posKarate, partitionKarate.keys (), node_size = 40, cmap = cmap, node_color = list (partitionKarate.values ()))
nx.draw_networkx_edges (GG_Karate, posKarate, alpha = 0.5)

plt.figure (figsize = (15, 15))
plt.title ("FOOTBALL CLUB NETWORK")
cmap = cm.get_cmap ('viridis', max (partitionFootball.values ()) + 1)
nx.draw_networkx_nodes (GG_Football, posFootball, partitionFootball.keys (), node_size = 40, cmap = cmap, node_color = list (partitionFootball.values ()))
nx.draw_networkx_edges (GG_Football, posFootball, alpha = 0.5)

plt.figure (figsize = (15, 15))
plt.title ("DOLPHIN NETWORK NETWORK")
cmap = cm.get_cmap ('viridis', max (partitionDolphin.values ()) + 1)
nx.draw_networkx_nodes (GG_Dolphin, posDolphin, partitionDolphin.keys (), node_size = 40, cmap = cmap, node_color = list (partitionDolphin.values ()))
nx.draw_networkx_edges (GG_Dolphin, posDolphin, alpha = 0.5)

plt.show ()
import community as community_louvain
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import networkx as nx

import io
import zipfile

GG_Karate = nx.karate_club_graph () # Karate Club
partitionKarate = community_louvain.best_partition (GG_Karate)
posKarate = nx.spring_layout (GG_Karate)
plt.figure (figsize = (15, 15))
cmap = cm.get_cmap ('viridis', max (partitionKarate.values ()) + 1)
nx.draw_networkx_nodes (GG_Karate, posKarate, partitionKarate.keys (), node_size = 40, cmap = cmap, node_color = list (partitionKarate.values ()))
nx.draw_networkx_edges (GG_Karate, posKarate, alpha = 0.5)
plt.show ()

zfFootball = zipfile.ZipFile ("football.zip")
txtFootball = zfFootball.read ("football.txt").decode ()
gmlFootball = zfFootball.read ("football.gml").decode ()
gmlFootball = gmlFootball.split ("\n") [1:]

GG_Football = nx.parse_gml (gmlFootball) # Football Club
partitionFootball = community_louvain.best_partition (GG_Football)
posFootball = nx.spring_layout (GG_Football)
plt.figure (figsize = (15, 15))
cmap = cm.get_cmap ('viridis', max (partitionFootball.values ()) + 1)
nx.draw_networkx_nodes (GG_Football, posFootball, partitionFootball.keys (), node_size = 40, cmap = cmap, node_color = list (partitionFootball.values ()))
nx.draw_networkx_edges (GG_Football, posFootball, alpha = 0.5)
plt.show ()

zfDolphin = zipfile.ZipFile ("dolphins.zip")
txtDolphin = zfDolphin.read ("dolphins.txt").decode ()
gmlDolphin = zfDolphin.read ("dolphins.gml").decode ()
gmlDolphin = gmlDolphin.split ("\n") [1:]

GG_Dolphin = nx.parse_gml (gmlDolphin) # Dolphin Graph
partitionDolphin = community_louvain.best_partition (GG_Dolphin)
posDolphin = nx.spring_layout (GG_Dolphin)
plt.figure (figsize = (15, 15))
cmap = cm.get_cmap ('viridis', max (partitionDolphin.values ()) + 1)
nx.draw_networkx_nodes (GG_Dolphin, posDolphin, partitionDolphin.keys (), node_size = 40, cmap = cmap, node_color = list (partitionDolphin.values ()))
nx.draw_networkx_edges (GG_Dolphin, posDolphin, alpha = 0.5)
plt.show ()

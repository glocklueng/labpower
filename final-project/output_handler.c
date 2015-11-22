
#define NUM_SAMPLES 2000

int sine_lut[2000] = 
 {
	0, 
	0.003141587, 
	0.006283144, 
	0.009424638, 
	0.01256604, 
	0.015707317, 
	0.01884844, 
	0.021989376, 
	0.025130095, 
	0.028270567, 
	0.031410759, 
	0.034550641, 
	0.037690183, 
	0.040829352, 
	0.043968118, 
	0.047106451, 
	0.050244318, 
	0.05338169, 
	0.056518534, 
	0.059654821, 
	0.06279052, 
	0.065925598, 
	0.069060026, 
	0.072193772, 
	0.075326806, 
	0.078459096, 
	0.081590612, 
	0.084721322, 
	0.087851197, 
	0.090980204, 
	0.094108313, 
	0.097235494, 
	0.100361715, 
	0.103486945, 
	0.106611154, 
	0.109734311, 
	0.112856385, 
	0.115977345, 
	0.11909716, 
	0.1222158, 
	0.125333234, 
	0.12844943, 
	0.131564359, 
	0.134677989, 
	0.137790291, 
	0.140901232, 
	0.144010783, 
	0.147118912, 
	0.150225589, 
	0.153330784, 
	0.156434465, 
	0.159536602, 
	0.162637165, 
	0.165736123, 
	0.168833445, 
	0.1719291, 
	0.175023059, 
	0.17811529, 
	0.181205764, 
	0.184294449, 
	0.187381315, 
	0.190466331, 
	0.193549468, 
	0.196630695, 
	0.199709981, 
	0.202787295, 
	0.205862609, 
	0.20893589, 
	0.21200711, 
	0.215076237, 
	0.218143241, 
	0.221208093, 
	0.224270761, 
	0.227331216, 
	0.230389427, 
	0.233445364, 
	0.236498997, 
	0.239550296, 
	0.242599231, 
	0.245645771, 
	0.248689887, 
	0.251731549, 
	0.254770726, 
	0.257807388, 
	0.260841506, 
	0.26387305, 
	0.266901989, 
	0.269928294, 
	0.272951936, 
	0.275972883, 
	0.278991106, 
	0.282006576, 
	0.285019262, 
	0.288029136, 
	0.291036167, 
	0.294040325, 
	0.297041582, 
	0.300039906, 
	0.30303527, 
	0.306027642, 
	0.309016994, 
	0.312003297, 
	0.31498652, 
	0.317966634, 
	0.32094361, 
	0.323917418, 
	0.32688803, 
	0.329855415, 
	0.332819545, 
	0.335780389, 
	0.33873792, 
	0.341692108, 
	0.344642923, 
	0.347590337, 
	0.35053432, 
	0.353474844, 
	0.356411879, 
	0.359345396, 
	0.362275367, 
	0.365201762, 
	0.368124553, 
	0.37104371, 
	0.373959206, 
	0.37687101, 
	0.379779096, 
	0.382683432, 
	0.385583992, 
	0.388480747, 
	0.391373667, 
	0.394262724, 
	0.397147891, 
	0.400029137, 
	0.402906436, 
	0.405779758, 
	0.408649075, 
	0.411514359, 
	0.414375581, 
	0.417232714, 
	0.420085728, 
	0.422934597, 
	0.425779292, 
	0.428619784, 
	0.431456046, 
	0.434288049, 
	0.437115767, 
	0.43993917, 
	0.442758231, 
	0.445572922, 
	0.448383216, 
	0.451189084, 
	0.4539905, 
	0.456787434, 
	0.459579861, 
	0.462367751, 
	0.465151078, 
	0.467929814, 
	0.470703932, 
	0.473473404, 
	0.476238204, 
	0.478998303, 
	0.481753674, 
	0.484504291, 
	0.487250126, 
	0.489991152, 
	0.492727342, 
	0.495458668, 
	0.498185105, 
	0.500906625, 
	0.503623202, 
	0.506334807, 
	0.509041416, 
	0.511743, 
	0.514439534, 
	0.51713099, 
	0.519817343, 
	0.522498565, 
	0.52517463, 
	0.527845512, 
	0.530511184, 
	0.533171621, 
	0.535826795, 
	0.538476681, 
	0.541121252, 
	0.543760483, 
	0.546394347, 
	0.549022818, 
	0.551645871, 
	0.554263479, 
	0.556875616, 
	0.559482258, 
	0.562083378, 
	0.56467895, 
	0.567268949, 
	0.569853349, 
	0.572432126, 
	0.575005252, 
	0.577572703, 
	0.580134454, 
	0.58269048, 
	0.585240754, 
	0.587785252, 
	0.590323949, 
	0.59285682, 
	0.59538384, 
	0.597904983, 
	0.600420225, 
	0.602929542, 
	0.605432907, 
	0.607930298, 
	0.610421688, 
	0.612907054, 
	0.61538637, 
	0.617859613, 
	0.620326758, 
	0.62278778, 
	0.625242656, 
	0.627691361, 
	0.630133871, 
	0.632570162, 
	0.635000209, 
	0.63742399, 
	0.639841479, 
	0.642252653, 
	0.644657489, 
	0.647055962, 
	0.649448048, 
	0.651833725, 
	0.654212969, 
	0.656585756, 
	0.658952062, 
	0.661311865, 
	0.663665141, 
	0.666011867, 
	0.66835202, 
	0.670685577, 
	0.673012514, 
	0.675332808, 
	0.677646437, 
	0.679953379, 
	0.682253609, 
	0.684547106, 
	0.686833847, 
	0.689113808, 
	0.691386969, 
	0.693653306, 
	0.695912797, 
	0.698165419, 
	0.700411151, 
	0.70264997, 
	0.704881854, 
	0.707106781, 
	0.70932473, 
	0.711535677, 
	0.713739602, 
	0.715936483, 
	0.718126298, 
	0.720309025, 
	0.722484643, 
	0.72465313, 
	0.726814465, 
	0.728968627, 
	0.731115595, 
	0.733255346, 
	0.735387861, 
	0.737513117, 
	0.739631095, 
	0.741741773, 
	0.74384513, 
	0.745941145, 
	0.748029799, 
	0.75011107, 
	0.752184937, 
	0.754251381, 
	0.75631038, 
	0.758361915, 
	0.760405966, 
	0.762442511, 
	0.764471531, 
	0.766493007, 
	0.768506917, 
	0.770513243, 
	0.772511964, 
	0.77450306, 
	0.776486513, 
	0.778462302, 
	0.780430407, 
	0.782390811, 
	0.784343492, 
	0.786288432, 
	0.788225612, 
	0.790155012, 
	0.792076614, 
	0.793990399, 
	0.795896347, 
	0.79779444, 
	0.799684658, 
	0.801566985, 
	0.8034414, 
	0.805307886, 
	0.807166423, 
	0.809016994, 
	0.810859581, 
	0.812694164, 
	0.814520727, 
	0.816339251, 
	0.818149717, 
	0.819952109, 
	0.821746409, 
	0.823532598, 
	0.825310659, 
	0.827080574, 
	0.828842327, 
	0.830595899, 
	0.832341274, 
	0.834078434, 
	0.835807361, 
	0.83752804, 
	0.839240453, 
	0.840944582, 
	0.842640412, 
	0.844327926, 
	0.846007106, 
	0.847677936, 
	0.8493404, 
	0.850994482, 
	0.852640164, 
	0.854277432, 
	0.855906268, 
	0.857526656, 
	0.859138581, 
	0.860742027, 
	0.862336978, 
	0.863923417, 
	0.86550133, 
	0.867070701, 
	0.868631514, 
	0.870183755, 
	0.871727407, 
	0.873262455, 
	0.874788884, 
	0.87630668, 
	0.877815827, 
	0.87931631, 
	0.880808115, 
	0.882291226, 
	0.88376563, 
	0.885231311, 
	0.886688256, 
	0.888136449, 
	0.889575876, 
	0.891006524, 
	0.892428378, 
	0.893841424, 
	0.895245648, 
	0.896641037, 
	0.898027576, 
	0.899405252, 
	0.900774051, 
	0.902133959, 
	0.903484964, 
	0.904827052, 
	0.90616021, 
	0.907484425, 
	0.908799682, 
	0.910105971, 
	0.911403277, 
	0.912691587, 
	0.91397089, 
	0.915241173, 
	0.916502422, 
	0.917754626, 
	0.918997772, 
	0.920231847, 
	0.921456841, 
	0.92267274, 
	0.923879533, 
	0.925077207, 
	0.926265751, 
	0.927445153, 
	0.928615402, 
	0.929776486, 
	0.930928393, 
	0.932071112, 
	0.933204633, 
	0.934328942, 
	0.935444031, 
	0.936549887, 
	0.937646499, 
	0.938733858, 
	0.939811951, 
	0.940880769, 
	0.941940301, 
	0.942990536, 
	0.944031464, 
	0.945063075, 
	0.946085359, 
	0.947098305, 
	0.948101904, 
	0.949096145, 
	0.950081019, 
	0.951056516, 
	0.952022627, 
	0.952979342, 
	0.953926651, 
	0.954864545, 
	0.955793015, 
	0.956712052, 
	0.957621646, 
	0.958521789, 
	0.959412472, 
	0.960293686, 
	0.961165422, 
	0.962027672, 
	0.962880427, 
	0.963723678, 
	0.964557418, 
	0.965381639, 
	0.966196331, 
	0.967001488, 
	0.9677971, 
	0.968583161, 
	0.969359662, 
	0.970126596, 
	0.970883956, 
	0.971631733, 
	0.97236992, 
	0.973098511, 
	0.973817497, 
	0.974526873, 
	0.97522663, 
	0.975916762, 
	0.976597262, 
	0.977268124, 
	0.97792934, 
	0.978580904, 
	0.979222811, 
	0.979855052, 
	0.980477623, 
	0.981090517, 
	0.981693729, 
	0.982287251, 
	0.982871078, 
	0.983445205, 
	0.984009626, 
	0.984564335, 
	0.985109326, 
	0.985644595, 
	0.986170136, 
	0.986685944, 
	0.987192014, 
	0.987688341, 
	0.988174919, 
	0.988651745, 
	0.989118813, 
	0.989576119, 
	0.990023658, 
	0.990461426, 
	0.990889418, 
	0.991307631, 
	0.99171606, 
	0.992114701, 
	0.992503551, 
	0.992882605, 
	0.993251859, 
	0.993611311, 
	0.993960955, 
	0.99430079, 
	0.994630812, 
	0.994951017, 
	0.995261402, 
	0.995561965, 
	0.995852701, 
	0.996133609, 
	0.996404686, 
	0.996665928, 
	0.996917334, 
	0.9971589, 
	0.997390625, 
	0.997612506, 
	0.997824541, 
	0.998026728, 
	0.998219065, 
	0.99840155, 
	0.998574181, 
	0.998736957, 
	0.998889875, 
	0.999032935, 
	0.999166134, 
	0.999289473, 
	0.999402948, 
	0.99950656, 
	0.999600308, 
	0.999684189, 
	0.999758204, 
	0.999822352, 
	0.999876632, 
	0.999921044, 
	0.999955587, 
	0.999980261, 
	0.999995065, 
	1, 
	0.999995065, 
	0.999980261, 
	0.999955587, 
	0.999921044, 
	0.999876632, 
	0.999822352, 
	0.999758204, 
	0.999684189, 
	0.999600308, 
	0.99950656, 
	0.999402948, 
	0.999289473, 
	0.999166134, 
	0.999032935, 
	0.998889875, 
	0.998736957, 
	0.998574181, 
	0.99840155, 
	0.998219065, 
	0.998026728, 
	0.997824541, 
	0.997612506, 
	0.997390625, 
	0.9971589, 
	0.996917334, 
	0.996665928, 
	0.996404686, 
	0.996133609, 
	0.995852701, 
	0.995561965, 
	0.995261402, 
	0.994951017, 
	0.994630812, 
	0.99430079, 
	0.993960955, 
	0.993611311, 
	0.993251859, 
	0.992882605, 
	0.992503551, 
	0.992114701, 
	0.99171606, 
	0.991307631, 
	0.990889418, 
	0.990461426, 
	0.990023658, 
	0.989576119, 
	0.989118813, 
	0.988651745, 
	0.988174919, 
	0.987688341, 
	0.987192014, 
	0.986685944, 
	0.986170136, 
	0.985644595, 
	0.985109326, 
	0.984564335, 
	0.984009626, 
	0.983445205, 
	0.982871078, 
	0.982287251, 
	0.981693729, 
	0.981090517, 
	0.980477623, 
	0.979855052, 
	0.979222811, 
	0.978580904, 
	0.97792934, 
	0.977268124, 
	0.976597262, 
	0.975916762, 
	0.97522663, 
	0.974526873, 
	0.973817497, 
	0.973098511, 
	0.97236992, 
	0.971631733, 
	0.970883956, 
	0.970126596, 
	0.969359662, 
	0.968583161, 
	0.9677971, 
	0.967001488, 
	0.966196331, 
	0.965381639, 
	0.964557418, 
	0.963723678, 
	0.962880427, 
	0.962027672, 
	0.961165422, 
	0.960293686, 
	0.959412472, 
	0.958521789, 
	0.957621646, 
	0.956712052, 
	0.955793015, 
	0.954864545, 
	0.953926651, 
	0.952979342, 
	0.952022627, 
	0.951056516, 
	0.950081019, 
	0.949096145, 
	0.948101904, 
	0.947098305, 
	0.946085359, 
	0.945063075, 
	0.944031464, 
	0.942990536, 
	0.941940301, 
	0.940880769, 
	0.939811951, 
	0.938733858, 
	0.937646499, 
	0.936549887, 
	0.935444031, 
	0.934328942, 
	0.933204633, 
	0.932071112, 
	0.930928393, 
	0.929776486, 
	0.928615402, 
	0.927445153, 
	0.926265751, 
	0.925077207, 
	0.923879533, 
	0.92267274, 
	0.921456841, 
	0.920231847, 
	0.918997772, 
	0.917754626, 
	0.916502422, 
	0.915241173, 
	0.91397089, 
	0.912691587, 
	0.911403277, 
	0.910105971, 
	0.908799682, 
	0.907484425, 
	0.90616021, 
	0.904827052, 
	0.903484964, 
	0.902133959, 
	0.900774051, 
	0.899405252, 
	0.898027576, 
	0.896641037, 
	0.895245648, 
	0.893841424, 
	0.892428378, 
	0.891006524, 
	0.889575876, 
	0.888136449, 
	0.886688256, 
	0.885231311, 
	0.88376563, 
	0.882291226, 
	0.880808115, 
	0.87931631, 
	0.877815827, 
	0.87630668, 
	0.874788884, 
	0.873262455, 
	0.871727407, 
	0.870183755, 
	0.868631514, 
	0.867070701, 
	0.86550133, 
	0.863923417, 
	0.862336978, 
	0.860742027, 
	0.859138581, 
	0.857526656, 
	0.855906268, 
	0.854277432, 
	0.852640164, 
	0.850994482, 
	0.8493404, 
	0.847677936, 
	0.846007106, 
	0.844327926, 
	0.842640412, 
	0.840944582, 
	0.839240453, 
	0.83752804, 
	0.835807361, 
	0.834078434, 
	0.832341274, 
	0.830595899, 
	0.828842327, 
	0.827080574, 
	0.825310659, 
	0.823532598, 
	0.821746409, 
	0.819952109, 
	0.818149717, 
	0.816339251, 
	0.814520727, 
	0.812694164, 
	0.810859581, 
	0.809016994, 
	0.807166423, 
	0.805307886, 
	0.8034414, 
	0.801566985, 
	0.799684658, 
	0.79779444, 
	0.795896347, 
	0.793990399, 
	0.792076614, 
	0.790155012, 
	0.788225612, 
	0.786288432, 
	0.784343492, 
	0.782390811, 
	0.780430407, 
	0.778462302, 
	0.776486513, 
	0.77450306, 
	0.772511964, 
	0.770513243, 
	0.768506917, 
	0.766493007, 
	0.764471531, 
	0.762442511, 
	0.760405966, 
	0.758361915, 
	0.75631038, 
	0.754251381, 
	0.752184937, 
	0.75011107, 
	0.748029799, 
	0.745941145, 
	0.74384513, 
	0.741741773, 
	0.739631095, 
	0.737513117, 
	0.735387861, 
	0.733255346, 
	0.731115595, 
	0.728968627, 
	0.726814465, 
	0.72465313, 
	0.722484643, 
	0.720309025, 
	0.718126298, 
	0.715936483, 
	0.713739602, 
	0.711535677, 
	0.70932473, 
	0.707106781, 
	0.704881854, 
	0.70264997, 
	0.700411151, 
	0.698165419, 
	0.695912797, 
	0.693653306, 
	0.691386969, 
	0.689113808, 
	0.686833847, 
	0.684547106, 
	0.682253609, 
	0.679953379, 
	0.677646437, 
	0.675332808, 
	0.673012514, 
	0.670685577, 
	0.66835202, 
	0.666011867, 
	0.663665141, 
	0.661311865, 
	0.658952062, 
	0.656585756, 
	0.654212969, 
	0.651833725, 
	0.649448048, 
	0.647055962, 
	0.644657489, 
	0.642252653, 
	0.639841479, 
	0.63742399, 
	0.635000209, 
	0.632570162, 
	0.630133871, 
	0.627691361, 
	0.625242656, 
	0.62278778, 
	0.620326758, 
	0.617859613, 
	0.61538637, 
	0.612907054, 
	0.610421688, 
	0.607930298, 
	0.605432907, 
	0.602929542, 
	0.600420225, 
	0.597904983, 
	0.59538384, 
	0.59285682, 
	0.590323949, 
	0.587785252, 
	0.585240754, 
	0.58269048, 
	0.580134454, 
	0.577572703, 
	0.575005252, 
	0.572432126, 
	0.569853349, 
	0.567268949, 
	0.56467895, 
	0.562083378, 
	0.559482258, 
	0.556875616, 
	0.554263479, 
	0.551645871, 
	0.549022818, 
	0.546394347, 
	0.543760483, 
	0.541121252, 
	0.538476681, 
	0.535826795, 
	0.533171621, 
	0.530511184, 
	0.527845512, 
	0.52517463, 
	0.522498565, 
	0.519817343, 
	0.51713099, 
	0.514439534, 
	0.511743, 
	0.509041416, 
	0.506334807, 
	0.503623202, 
	0.500906625, 
	0.498185105, 
	0.495458668, 
	0.492727342, 
	0.489991152, 
	0.487250126, 
	0.484504291, 
	0.481753674, 
	0.478998303, 
	0.476238204, 
	0.473473404, 
	0.470703932, 
	0.467929814, 
	0.465151078, 
	0.462367751, 
	0.459579861, 
	0.456787434, 
	0.4539905, 
	0.451189084, 
	0.448383216, 
	0.445572922, 
	0.442758231, 
	0.43993917, 
	0.437115767, 
	0.434288049, 
	0.431456046, 
	0.428619784, 
	0.425779292, 
	0.422934597, 
	0.420085728, 
	0.417232714, 
	0.414375581, 
	0.411514359, 
	0.408649075, 
	0.405779758, 
	0.402906436, 
	0.400029137, 
	0.397147891, 
	0.394262724, 
	0.391373667, 
	0.388480747, 
	0.385583992, 
	0.382683432, 
	0.379779096, 
	0.37687101, 
	0.373959206, 
	0.37104371, 
	0.368124553, 
	0.365201762, 
	0.362275367, 
	0.359345396, 
	0.356411879, 
	0.353474844, 
	0.35053432, 
	0.347590337, 
	0.344642923, 
	0.341692108, 
	0.33873792, 
	0.335780389, 
	0.332819545, 
	0.329855415, 
	0.32688803, 
	0.323917418, 
	0.32094361, 
	0.317966634, 
	0.31498652, 
	0.312003297, 
	0.309016994, 
	0.306027642, 
	0.30303527, 
	0.300039906, 
	0.297041582, 
	0.294040325, 
	0.291036167, 
	0.288029136, 
	0.285019262, 
	0.282006576, 
	0.278991106, 
	0.275972883, 
	0.272951936, 
	0.269928294, 
	0.266901989, 
	0.26387305, 
	0.260841506, 
	0.257807388, 
	0.254770726, 
	0.251731549, 
	0.248689887, 
	0.245645771, 
	0.242599231, 
	0.239550296, 
	0.236498997, 
	0.233445364, 
	0.230389427, 
	0.227331216, 
	0.224270761, 
	0.221208093, 
	0.218143241, 
	0.215076237, 
	0.21200711, 
	0.20893589, 
	0.205862609, 
	0.202787295, 
	0.199709981, 
	0.196630695, 
	0.193549468, 
	0.190466331, 
	0.187381315, 
	0.184294449, 
	0.181205764, 
	0.17811529, 
	0.175023059, 
	0.1719291, 
	0.168833445, 
	0.165736123, 
	0.162637165, 
	0.159536602, 
	0.156434465, 
	0.153330784, 
	0.150225589, 
	0.147118912, 
	0.144010783, 
	0.140901232, 
	0.137790291, 
	0.134677989, 
	0.131564359, 
	0.12844943, 
	0.125333234, 
	0.1222158, 
	0.11909716, 
	0.115977345, 
	0.112856385, 
	0.109734311, 
	0.106611154, 
	0.103486945, 
	0.100361715, 
	0.097235494, 
	0.094108313, 
	0.090980204, 
	0.087851197, 
	0.084721322, 
	0.081590612, 
	0.078459096, 
	0.075326806, 
	0.072193772, 
	0.069060026, 
	0.065925598, 
	0.06279052, 
	0.059654821, 
	0.056518534, 
	0.05338169, 
	0.050244318, 
	0.047106451, 
	0.043968118, 
	0.040829352, 
	0.037690183, 
	0.034550641, 
	0.031410759, 
	0.028270567, 
	0.025130095, 
	0.021989376, 
	0.01884844, 
	0.015707317, 
	0.01256604, 
	0.009424638, 
	0.006283144, 
	0.003141587, 
	1.22515E-16, 
	-0.003141587, 
	-0.006283144, 
	-0.009424638, 
	-0.01256604, 
	-0.015707317, 
	-0.01884844, 
	-0.021989376, 
	-0.025130095, 
	-0.028270567, 
	-0.031410759, 
	-0.034550641, 
	-0.037690183, 
	-0.040829352, 
	-0.043968118, 
	-0.047106451, 
	-0.050244318, 
	-0.05338169, 
	-0.056518534, 
	-0.059654821, 
	-0.06279052, 
	-0.065925598, 
	-0.069060026, 
	-0.072193772, 
	-0.075326806, 
	-0.078459096, 
	-0.081590612, 
	-0.084721322, 
	-0.087851197, 
	-0.090980204, 
	-0.094108313, 
	-0.097235494, 
	-0.100361715, 
	-0.103486945, 
	-0.106611154, 
	-0.109734311, 
	-0.112856385, 
	-0.115977345, 
	-0.11909716, 
	-0.1222158, 
	-0.125333234, 
	-0.12844943, 
	-0.131564359, 
	-0.134677989, 
	-0.137790291, 
	-0.140901232, 
	-0.144010783, 
	-0.147118912, 
	-0.150225589, 
	-0.153330784, 
	-0.156434465, 
	-0.159536602, 
	-0.162637165, 
	-0.165736123, 
	-0.168833445, 
	-0.1719291, 
	-0.175023059, 
	-0.17811529, 
	-0.181205764, 
	-0.184294449, 
	-0.187381315, 
	-0.190466331, 
	-0.193549468, 
	-0.196630695, 
	-0.199709981, 
	-0.202787295, 
	-0.205862609, 
	-0.20893589, 
	-0.21200711, 
	-0.215076237, 
	-0.218143241, 
	-0.221208093, 
	-0.224270761, 
	-0.227331216, 
	-0.230389427, 
	-0.233445364, 
	-0.236498997, 
	-0.239550296, 
	-0.242599231, 
	-0.245645771, 
	-0.248689887, 
	-0.251731549, 
	-0.254770726, 
	-0.257807388, 
	-0.260841506, 
	-0.26387305, 
	-0.266901989, 
	-0.269928294, 
	-0.272951936, 
	-0.275972883, 
	-0.278991106, 
	-0.282006576, 
	-0.285019262, 
	-0.288029136, 
	-0.291036167, 
	-0.294040325, 
	-0.297041582, 
	-0.300039906, 
	-0.30303527, 
	-0.306027642, 
	-0.309016994, 
	-0.312003297, 
	-0.31498652, 
	-0.317966634, 
	-0.32094361, 
	-0.323917418, 
	-0.32688803, 
	-0.329855415, 
	-0.332819545, 
	-0.335780389, 
	-0.33873792, 
	-0.341692108, 
	-0.344642923, 
	-0.347590337, 
	-0.35053432, 
	-0.353474844, 
	-0.356411879, 
	-0.359345396, 
	-0.362275367, 
	-0.365201762, 
	-0.368124553, 
	-0.37104371, 
	-0.373959206, 
	-0.37687101, 
	-0.379779096, 
	-0.382683432, 
	-0.385583992, 
	-0.388480747, 
	-0.391373667, 
	-0.394262724, 
	-0.397147891, 
	-0.400029137, 
	-0.402906436, 
	-0.405779758, 
	-0.408649075, 
	-0.411514359, 
	-0.414375581, 
	-0.417232714, 
	-0.420085728, 
	-0.422934597, 
	-0.425779292, 
	-0.428619784, 
	-0.431456046, 
	-0.434288049, 
	-0.437115767, 
	-0.43993917, 
	-0.442758231, 
	-0.445572922, 
	-0.448383216, 
	-0.451189084, 
	-0.4539905, 
	-0.456787434, 
	-0.459579861, 
	-0.462367751, 
	-0.465151078, 
	-0.467929814, 
	-0.470703932, 
	-0.473473404, 
	-0.476238204, 
	-0.478998303, 
	-0.481753674, 
	-0.484504291, 
	-0.487250126, 
	-0.489991152, 
	-0.492727342, 
	-0.495458668, 
	-0.498185105, 
	-0.500906625, 
	-0.503623202, 
	-0.506334807, 
	-0.509041416, 
	-0.511743, 
	-0.514439534, 
	-0.51713099, 
	-0.519817343, 
	-0.522498565, 
	-0.52517463, 
	-0.527845512, 
	-0.530511184, 
	-0.533171621, 
	-0.535826795, 
	-0.538476681, 
	-0.541121252, 
	-0.543760483, 
	-0.546394347, 
	-0.549022818, 
	-0.551645871, 
	-0.554263479, 
	-0.556875616, 
	-0.559482258, 
	-0.562083378, 
	-0.56467895, 
	-0.567268949, 
	-0.569853349, 
	-0.572432126, 
	-0.575005252, 
	-0.577572703, 
	-0.580134454, 
	-0.58269048, 
	-0.585240754, 
	-0.587785252, 
	-0.590323949, 
	-0.59285682, 
	-0.59538384, 
	-0.597904983, 
	-0.600420225, 
	-0.602929542, 
	-0.605432907, 
	-0.607930298, 
	-0.610421688, 
	-0.612907054, 
	-0.61538637, 
	-0.617859613, 
	-0.620326758, 
	-0.62278778, 
	-0.625242656, 
	-0.627691361, 
	-0.630133871, 
	-0.632570162, 
	-0.635000209, 
	-0.63742399, 
	-0.639841479, 
	-0.642252653, 
	-0.644657489, 
	-0.647055962, 
	-0.649448048, 
	-0.651833725, 
	-0.654212969, 
	-0.656585756, 
	-0.658952062, 
	-0.661311865, 
	-0.663665141, 
	-0.666011867, 
	-0.66835202, 
	-0.670685577, 
	-0.673012514, 
	-0.675332808, 
	-0.677646437, 
	-0.679953379, 
	-0.682253609, 
	-0.684547106, 
	-0.686833847, 
	-0.689113808, 
	-0.691386969, 
	-0.693653306, 
	-0.695912797, 
	-0.698165419, 
	-0.700411151, 
	-0.70264997, 
	-0.704881854, 
	-0.707106781, 
	-0.70932473, 
	-0.711535677, 
	-0.713739602, 
	-0.715936483, 
	-0.718126298, 
	-0.720309025, 
	-0.722484643, 
	-0.72465313, 
	-0.726814465, 
	-0.728968627, 
	-0.731115595, 
	-0.733255346, 
	-0.735387861, 
	-0.737513117, 
	-0.739631095, 
	-0.741741773, 
	-0.74384513, 
	-0.745941145, 
	-0.748029799, 
	-0.75011107, 
	-0.752184937, 
	-0.754251381, 
	-0.75631038, 
	-0.758361915, 
	-0.760405966, 
	-0.762442511, 
	-0.764471531, 
	-0.766493007, 
	-0.768506917, 
	-0.770513243, 
	-0.772511964, 
	-0.77450306, 
	-0.776486513, 
	-0.778462302, 
	-0.780430407, 
	-0.782390811, 
	-0.784343492, 
	-0.786288432, 
	-0.788225612, 
	-0.790155012, 
	-0.792076614, 
	-0.793990399, 
	-0.795896347, 
	-0.79779444, 
	-0.799684658, 
	-0.801566985, 
	-0.8034414, 
	-0.805307886, 
	-0.807166423, 
	-0.809016994, 
	-0.810859581, 
	-0.812694164, 
	-0.814520727, 
	-0.816339251, 
	-0.818149717, 
	-0.819952109, 
	-0.821746409, 
	-0.823532598, 
	-0.825310659, 
	-0.827080574, 
	-0.828842327, 
	-0.830595899, 
	-0.832341274, 
	-0.834078434, 
	-0.835807361, 
	-0.83752804, 
	-0.839240453, 
	-0.840944582, 
	-0.842640412, 
	-0.844327926, 
	-0.846007106, 
	-0.847677936, 
	-0.8493404, 
	-0.850994482, 
	-0.852640164, 
	-0.854277432, 
	-0.855906268, 
	-0.857526656, 
	-0.859138581, 
	-0.860742027, 
	-0.862336978, 
	-0.863923417, 
	-0.86550133, 
	-0.867070701, 
	-0.868631514, 
	-0.870183755, 
	-0.871727407, 
	-0.873262455, 
	-0.874788884, 
	-0.87630668, 
	-0.877815827, 
	-0.87931631, 
	-0.880808115, 
	-0.882291226, 
	-0.88376563, 
	-0.885231311, 
	-0.886688256, 
	-0.888136449, 
	-0.889575876, 
	-0.891006524, 
	-0.892428378, 
	-0.893841424, 
	-0.895245648, 
	-0.896641037, 
	-0.898027576, 
	-0.899405252, 
	-0.900774051, 
	-0.902133959, 
	-0.903484964, 
	-0.904827052, 
	-0.90616021, 
	-0.907484425, 
	-0.908799682, 
	-0.910105971, 
	-0.911403277, 
	-0.912691587, 
	-0.91397089, 
	-0.915241173, 
	-0.916502422, 
	-0.917754626, 
	-0.918997772, 
	-0.920231847, 
	-0.921456841, 
	-0.92267274, 
	-0.923879533, 
	-0.925077207, 
	-0.926265751, 
	-0.927445153, 
	-0.928615402, 
	-0.929776486, 
	-0.930928393, 
	-0.932071112, 
	-0.933204633, 
	-0.934328942, 
	-0.935444031, 
	-0.936549887, 
	-0.937646499, 
	-0.938733858, 
	-0.939811951, 
	-0.940880769, 
	-0.941940301, 
	-0.942990536, 
	-0.944031464, 
	-0.945063075, 
	-0.946085359, 
	-0.947098305, 
	-0.948101904, 
	-0.949096145, 
	-0.950081019, 
	-0.951056516, 
	-0.952022627, 
	-0.952979342, 
	-0.953926651, 
	-0.954864545, 
	-0.955793015, 
	-0.956712052, 
	-0.957621646, 
	-0.958521789, 
	-0.959412472, 
	-0.960293686, 
	-0.961165422, 
	-0.962027672, 
	-0.962880427, 
	-0.963723678, 
	-0.964557418, 
	-0.965381639, 
	-0.966196331, 
	-0.967001488, 
	-0.9677971, 
	-0.968583161, 
	-0.969359662, 
	-0.970126596, 
	-0.970883956, 
	-0.971631733, 
	-0.97236992, 
	-0.973098511, 
	-0.973817497, 
	-0.974526873, 
	-0.97522663, 
	-0.975916762, 
	-0.976597262, 
	-0.977268124, 
	-0.97792934, 
	-0.978580904, 
	-0.979222811, 
	-0.979855052, 
	-0.980477623, 
	-0.981090517, 
	-0.981693729, 
	-0.982287251, 
	-0.982871078, 
	-0.983445205, 
	-0.984009626, 
	-0.984564335, 
	-0.985109326, 
	-0.985644595, 
	-0.986170136, 
	-0.986685944, 
	-0.987192014, 
	-0.987688341, 
	-0.988174919, 
	-0.988651745, 
	-0.989118813, 
	-0.989576119, 
	-0.990023658, 
	-0.990461426, 
	-0.990889418, 
	-0.991307631, 
	-0.99171606, 
	-0.992114701, 
	-0.992503551, 
	-0.992882605, 
	-0.993251859, 
	-0.993611311, 
	-0.993960955, 
	-0.99430079, 
	-0.994630812, 
	-0.994951017, 
	-0.995261402, 
	-0.995561965, 
	-0.995852701, 
	-0.996133609, 
	-0.996404686, 
	-0.996665928, 
	-0.996917334, 
	-0.9971589, 
	-0.997390625, 
	-0.997612506, 
	-0.997824541, 
	-0.998026728, 
	-0.998219065, 
	-0.99840155, 
	-0.998574181, 
	-0.998736957, 
	-0.998889875, 
	-0.999032935, 
	-0.999166134, 
	-0.999289473, 
	-0.999402948, 
	-0.99950656, 
	-0.999600308, 
	-0.999684189, 
	-0.999758204, 
	-0.999822352, 
	-0.999876632, 
	-0.999921044, 
	-0.999955587, 
	-0.999980261, 
	-0.999995065, 
	-1, 
	-0.999995065, 
	-0.999980261, 
	-0.999955587, 
	-0.999921044, 
	-0.999876632, 
	-0.999822352, 
	-0.999758204, 
	-0.999684189, 
	-0.999600308, 
	-0.99950656, 
	-0.999402948, 
	-0.999289473, 
	-0.999166134, 
	-0.999032935, 
	-0.998889875, 
	-0.998736957, 
	-0.998574181, 
	-0.99840155, 
	-0.998219065, 
	-0.998026728, 
	-0.997824541, 
	-0.997612506, 
	-0.997390625, 
	-0.9971589, 
	-0.996917334, 
	-0.996665928, 
	-0.996404686, 
	-0.996133609, 
	-0.995852701, 
	-0.995561965, 
	-0.995261402, 
	-0.994951017, 
	-0.994630812, 
	-0.99430079, 
	-0.993960955, 
	-0.993611311, 
	-0.993251859, 
	-0.992882605, 
	-0.992503551, 
	-0.992114701, 
	-0.99171606, 
	-0.991307631, 
	-0.990889418, 
	-0.990461426, 
	-0.990023658, 
	-0.989576119, 
	-0.989118813, 
	-0.988651745, 
	-0.988174919, 
	-0.987688341, 
	-0.987192014, 
	-0.986685944, 
	-0.986170136, 
	-0.985644595, 
	-0.985109326, 
	-0.984564335, 
	-0.984009626, 
	-0.983445205, 
	-0.982871078, 
	-0.982287251, 
	-0.981693729, 
	-0.981090517, 
	-0.980477623, 
	-0.979855052, 
	-0.979222811, 
	-0.978580904, 
	-0.97792934, 
	-0.977268124, 
	-0.976597262, 
	-0.975916762, 
	-0.97522663, 
	-0.974526873, 
	-0.973817497, 
	-0.973098511, 
	-0.97236992, 
	-0.971631733, 
	-0.970883956, 
	-0.970126596, 
	-0.969359662, 
	-0.968583161, 
	-0.9677971, 
	-0.967001488, 
	-0.966196331, 
	-0.965381639, 
	-0.964557418, 
	-0.963723678, 
	-0.962880427, 
	-0.962027672, 
	-0.961165422, 
	-0.960293686, 
	-0.959412472, 
	-0.958521789, 
	-0.957621646, 
	-0.956712052, 
	-0.955793015, 
	-0.954864545, 
	-0.953926651, 
	-0.952979342, 
	-0.952022627, 
	-0.951056516, 
	-0.950081019, 
	-0.949096145, 
	-0.948101904, 
	-0.947098305, 
	-0.946085359, 
	-0.945063075, 
	-0.944031464, 
	-0.942990536, 
	-0.941940301, 
	-0.940880769, 
	-0.939811951, 
	-0.938733858, 
	-0.937646499, 
	-0.936549887, 
	-0.935444031, 
	-0.934328942, 
	-0.933204633, 
	-0.932071112, 
	-0.930928393, 
	-0.929776486, 
	-0.928615402, 
	-0.927445153, 
	-0.926265751, 
	-0.925077207, 
	-0.923879533, 
	-0.92267274, 
	-0.921456841, 
	-0.920231847, 
	-0.918997772, 
	-0.917754626, 
	-0.916502422, 
	-0.915241173, 
	-0.91397089, 
	-0.912691587, 
	-0.911403277, 
	-0.910105971, 
	-0.908799682, 
	-0.907484425, 
	-0.90616021, 
	-0.904827052, 
	-0.903484964, 
	-0.902133959, 
	-0.900774051, 
	-0.899405252, 
	-0.898027576, 
	-0.896641037, 
	-0.895245648, 
	-0.893841424, 
	-0.892428378, 
	-0.891006524, 
	-0.889575876, 
	-0.888136449, 
	-0.886688256, 
	-0.885231311, 
	-0.88376563, 
	-0.882291226, 
	-0.880808115, 
	-0.87931631, 
	-0.877815827, 
	-0.87630668, 
	-0.874788884, 
	-0.873262455, 
	-0.871727407, 
	-0.870183755, 
	-0.868631514, 
	-0.867070701, 
	-0.86550133, 
	-0.863923417, 
	-0.862336978, 
	-0.860742027, 
	-0.859138581, 
	-0.857526656, 
	-0.855906268, 
	-0.854277432, 
	-0.852640164, 
	-0.850994482, 
	-0.8493404, 
	-0.847677936, 
	-0.846007106, 
	-0.844327926, 
	-0.842640412, 
	-0.840944582, 
	-0.839240453, 
	-0.83752804, 
	-0.835807361, 
	-0.834078434, 
	-0.832341274, 
	-0.830595899, 
	-0.828842327, 
	-0.827080574, 
	-0.825310659, 
	-0.823532598, 
	-0.821746409, 
	-0.819952109, 
	-0.818149717, 
	-0.816339251, 
	-0.814520727, 
	-0.812694164, 
	-0.810859581, 
	-0.809016994, 
	-0.807166423, 
	-0.805307886, 
	-0.8034414, 
	-0.801566985, 
	-0.799684658, 
	-0.79779444, 
	-0.795896347, 
	-0.793990399, 
	-0.792076614, 
	-0.790155012, 
	-0.788225612, 
	-0.786288432, 
	-0.784343492, 
	-0.782390811, 
	-0.780430407, 
	-0.778462302, 
	-0.776486513, 
	-0.77450306, 
	-0.772511964, 
	-0.770513243, 
	-0.768506917, 
	-0.766493007, 
	-0.764471531, 
	-0.762442511, 
	-0.760405966, 
	-0.758361915, 
	-0.75631038, 
	-0.754251381, 
	-0.752184937, 
	-0.75011107, 
	-0.748029799, 
	-0.745941145, 
	-0.74384513, 
	-0.741741773, 
	-0.739631095, 
	-0.737513117, 
	-0.735387861, 
	-0.733255346, 
	-0.731115595, 
	-0.728968627, 
	-0.726814465, 
	-0.72465313, 
	-0.722484643, 
	-0.720309025, 
	-0.718126298, 
	-0.715936483, 
	-0.713739602, 
	-0.711535677, 
	-0.70932473, 
	-0.707106781, 
	-0.704881854, 
	-0.70264997, 
	-0.700411151, 
	-0.698165419, 
	-0.695912797, 
	-0.693653306, 
	-0.691386969, 
	-0.689113808, 
	-0.686833847, 
	-0.684547106, 
	-0.682253609, 
	-0.679953379, 
	-0.677646437, 
	-0.675332808, 
	-0.673012514, 
	-0.670685577, 
	-0.66835202, 
	-0.666011867, 
	-0.663665141, 
	-0.661311865, 
	-0.658952062, 
	-0.656585756, 
	-0.654212969, 
	-0.651833725, 
	-0.649448048, 
	-0.647055962, 
	-0.644657489, 
	-0.642252653, 
	-0.639841479, 
	-0.63742399, 
	-0.635000209, 
	-0.632570162, 
	-0.630133871, 
	-0.627691361, 
	-0.625242656, 
	-0.62278778, 
	-0.620326758, 
	-0.617859613, 
	-0.61538637, 
	-0.612907054, 
	-0.610421688, 
	-0.607930298, 
	-0.605432907, 
	-0.602929542, 
	-0.600420225, 
	-0.597904983, 
	-0.59538384, 
	-0.59285682, 
	-0.590323949, 
	-0.587785252, 
	-0.585240754, 
	-0.58269048, 
	-0.580134454, 
	-0.577572703, 
	-0.575005252, 
	-0.572432126, 
	-0.569853349, 
	-0.567268949, 
	-0.56467895, 
	-0.562083378, 
	-0.559482258, 
	-0.556875616, 
	-0.554263479, 
	-0.551645871, 
	-0.549022818, 
	-0.546394347, 
	-0.543760483, 
	-0.541121252, 
	-0.538476681, 
	-0.535826795, 
	-0.533171621, 
	-0.530511184, 
	-0.527845512, 
	-0.52517463, 
	-0.522498565, 
	-0.519817343, 
	-0.51713099, 
	-0.514439534, 
	-0.511743, 
	-0.509041416, 
	-0.506334807, 
	-0.503623202, 
	-0.500906625, 
	-0.498185105, 
	-0.495458668, 
	-0.492727342, 
	-0.489991152, 
	-0.487250126, 
	-0.484504291, 
	-0.481753674, 
	-0.478998303, 
	-0.476238204, 
	-0.473473404, 
	-0.470703932, 
	-0.467929814, 
	-0.465151078, 
	-0.462367751, 
	-0.459579861, 
	-0.456787434, 
	-0.4539905, 
	-0.451189084, 
	-0.448383216, 
	-0.445572922, 
	-0.442758231, 
	-0.43993917, 
	-0.437115767, 
	-0.434288049, 
	-0.431456046, 
	-0.428619784, 
	-0.425779292, 
	-0.422934597, 
	-0.420085728, 
	-0.417232714, 
	-0.414375581, 
	-0.411514359, 
	-0.408649075, 
	-0.405779758, 
	-0.402906436, 
	-0.400029137, 
	-0.397147891, 
	-0.394262724, 
	-0.391373667, 
	-0.388480747, 
	-0.385583992, 
	-0.382683432, 
	-0.379779096, 
	-0.37687101, 
	-0.373959206, 
	-0.37104371, 
	-0.368124553, 
	-0.365201762, 
	-0.362275367, 
	-0.359345396, 
	-0.356411879, 
	-0.353474844, 
	-0.35053432, 
	-0.347590337, 
	-0.344642923, 
	-0.341692108, 
	-0.33873792, 
	-0.335780389, 
	-0.332819545, 
	-0.329855415, 
	-0.32688803, 
	-0.323917418, 
	-0.32094361, 
	-0.317966634, 
	-0.31498652, 
	-0.312003297, 
	-0.309016994, 
	-0.306027642, 
	-0.30303527, 
	-0.300039906, 
	-0.297041582, 
	-0.294040325, 
	-0.291036167, 
	-0.288029136, 
	-0.285019262, 
	-0.282006576, 
	-0.278991106, 
	-0.275972883, 
	-0.272951936, 
	-0.269928294, 
	-0.266901989, 
	-0.26387305, 
	-0.260841506, 
	-0.257807388, 
	-0.254770726, 
	-0.251731549, 
	-0.248689887, 
	-0.245645771, 
	-0.242599231, 
	-0.239550296, 
	-0.236498997, 
	-0.233445364, 
	-0.230389427, 
	-0.227331216, 
	-0.224270761, 
	-0.221208093, 
	-0.218143241, 
	-0.215076237, 
	-0.21200711, 
	-0.20893589, 
	-0.205862609, 
	-0.202787295, 
	-0.199709981, 
	-0.196630695, 
	-0.193549468, 
	-0.190466331, 
	-0.187381315, 
	-0.184294449, 
	-0.181205764, 
	-0.17811529, 
	-0.175023059, 
	-0.1719291, 
	-0.168833445, 
	-0.165736123, 
	-0.162637165, 
	-0.159536602, 
	-0.156434465, 
	-0.153330784, 
	-0.150225589, 
	-0.147118912, 
	-0.144010783, 
	-0.140901232, 
	-0.137790291, 
	-0.134677989, 
	-0.131564359, 
	-0.12844943, 
	-0.125333234, 
	-0.1222158, 
	-0.11909716, 
	-0.115977345, 
	-0.112856385, 
	-0.109734311, 
	-0.106611154, 
	-0.103486945, 
	-0.100361715, 
	-0.097235494, 
	-0.094108313, 
	-0.090980204, 
	-0.087851197, 
	-0.084721322, 
	-0.081590612, 
	-0.078459096, 
	-0.075326806, 
	-0.072193772, 
	-0.069060026, 
	-0.065925598, 
	-0.06279052, 
	-0.059654821, 
	-0.056518534, 
	-0.05338169, 
	-0.050244318, 
	-0.047106451, 
	-0.043968118, 
	-0.040829352, 
	-0.037690183, 
	-0.034550641, 
	-0.031410759, 
	-0.028270567, 
	-0.025130095, 
	-0.021989376, 
	-0.01884844, 
	-0.015707317, 
	-0.01256604, 
	-0.009424638, 
	-0.006283144, 
	-0.003141587 
 };


 void output_PWM() {

 }
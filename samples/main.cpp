#include <astra/astra.hpp>
#include <iostream>
using namespace std;

int main() 
{
	astra::initialize();
	astra::StreamSet sensor;
	astra::StreamReader reader = sensor.create_reader();

	auto bodyStream = reader.stream<astra::BodyStream>();
	bodyStream.start();
	astra :: SkeletonProfile profile = bodyStream.get_skeleton_profile();

	do {
		astra_update();
		auto frame = reader.get_latest_frame();
		astra :: BodyFrame bodyFrame = frame.get<astra::BodyFrame>();
		const auto& bodies = bodyFrame.bodies();
		for (const auto& body : bodies ) {
		const auto& joints = body.joints();

		for (const auto& joint : joints) {
			astra::JointType type = joint.type();
			const auto& pos = joint.depth_position();
			cout << pos.x << "," << pos.y <<  endl;


		}
		}


	} while(1);
}
